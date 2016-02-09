#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<long long,long long> point;
#define x first
#define y second

long long cross(point a, point o, point b) {
	long long dxao = o.x - a.x;
	long long dyao = o.y - a.y;
	long long dxob = b.x - o.x;
	long long dyob = b.y - o.y;
	return dxao * dyob - dxob * dyao;
}

bool collinear(point a, point o, point b) {
	return cross(a, o, b) == 0;
}

bool ccw(point a, point o, point b) {
	return cross(a, o, b) > 0;
}

point pivot;
point dot[N];

long long dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
	if(collinear(a, pivot, b)) {
		//pf("coli %I64d %I64d %I64d %I64d\n", a.x, a.y, b.x, b.y);
		return dist(a, pivot) < dist(b, pivot);
	}
	return ccw(b, pivot, a);
}

bool cmp(point a, point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

vector<point> ConvexHull(vector<point> P) {
  int i, j, n = (int) P.size();
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i].y < P[PO].y || (P[i].y == P[PO].y && P[i].x > P[PO].x)) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  int k = P.size() - 1;
  while(k && collinear(P[0], P[k-1], P[k])) k--;
  reverse(P.begin() + k, P.end());
  if(collinear(P[0], P[1], P.back())) {
    vector< point > S;
    S.push_back(P[0]);
    S.push_back(P.back());
    return S;
  }
  //FORS(i, P.size()) pf("%long longd %long longd\n", P[i].x, P[i].y);
  //puts("-");
  vector<point> S;
  S.push_back(P[n-1]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();
  }
  S.pop_back();
  return S;
}

// lands sudah dalam bentuk convex hull
// tree juga
// jangan lupa lands bisa siklik pas iterasi
// jangan lupa kalo tree 0
double solve(vector<point>& lands, vector<point>& tree) {
  int n = lands.size(), m = tree.size();
  long long ans = 0, now = 0;
  int j = 1;
  for(int i = 0; i<m; i++) {
    if(ccw(lands[0], tree[i], tree[j]))
      j = i;
  }
  int k = 1;
  for(int i = 0; i < n; i++) {
    while(ccw(lands[i], tree[(j+1) % m], tree[j])) j = (j + 1) % m;
    while(ccw(lands[i], lands[(k+1) % n], tree[j])) {
      now -= lands[k].x*lands[i].y - lands[i].x*lands[k].y;
      now += lands[k].x*lands[(k+1) % n].y - lands[(k+1)%n].x*lands[k].y;
      k = (k+1) % n;
      now += lands[k].x*lands[i].y - lands[i].x*lands[k].y;
    }
    ans = max(ans, now);
    now -= lands[k].x*lands[i].y - lands[i].x*lands[k].y;
    now -= lands[i].first*lands[(i+1) % n].second - lands[(i+1) % n].first*lands[i].second;
    now += lands[k].first*lands[(i+1) % n].second - lands[(i+1) % n].first*lands[k].second;
  }
  return (double) ans/2;
}

int main(void)
{
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    vector<point> lands;
    for(int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      lands.push_back(point(a, b));
    }
    int m;
    scanf("%d", &m);
    if(m == 0) {
      double ans = 0;
      for(int i = 0; i<n; i++) {
        ans += lands[i].x*lands[(i+1) % n].y - lands[(i+1) % n].x * lands[i].y;
      }
      printf("%.2f\n", ans/2);
      continue;
    }
    vector<point> tree;
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      tree.push_back(point(a, b));
    }
    lands = ConvexHull(lands);
    if(tree.size() > 2);
      tree = ConvexHull(tree);
    // cout << tree.size() << "\n";
    // for(int i = 0; i<tree.size(); i++) {
    //   cout << tree[i].x << " " << tree[i].y << "\n";
    // }
    printf("%.2f\n", solve(lands, tree));
  }
	return 0;
}