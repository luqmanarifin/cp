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

long long dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
	if(collinear(a, pivot, b)) {
		return dist(a, pivot) < dist(b, pivot);
	}
	return ccw(b, pivot, a);
}

bool cmp(point a, point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

// convex hull tidak siklik, P[0] tidak mengulang di P.back()
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

int main(void)
{
	int n;
  scanf("%d", &n);
  vector<point> p;
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p.push_back(point(a, b));
  }
  vector<point> ch = ConvexHull(p);
  cout << ch.size() << endl;
  for(auto it : ch) {
    printf("%I64d %I64d\n", it.x, it.y);
  }
	return 0;
}
