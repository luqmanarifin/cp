#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

typedef pair<LL,LL> point;
#define x first
#define y second

LL cross(point a, point o, point b) {
  LL dxao = o.x - a.x;
  LL dyao = o.y - a.y;
  LL dxob = b.x - o.x;
  LL dyob = b.y - o.y;
  return dxao * dyob - dxob * dyao;
}

bool collinear(point a, point o, point b) {
  return cross(a, o, b) == 0;
}

bool ccw(point a, point o, point b) {
  return cross(a, o, b) >= 0;
}

point pivot;

LL dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
  if(collinear(pivot, a, b)) {
    return dist(a, pivot) < dist(b, pivot);
  }
  LL xa = a.x - pivot.x;
  LL xb = b.x - pivot.x;
  LL ya = a.y - pivot.y;
  LL yb = b.y - pivot.y;
  return atan2(ya, xa) < atan2(yb, xb);
}

bool cmp(point a, point b) {
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}

vector<point> ConvexHull(vector<point> P) {
  int i, j, n = (int) P.size();
  int PO = 0;
  FOR(i, 1, n-1) {
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
  //FORS(i, P.size()) pf("%lld %lld\n", P[i].x, P[i].y);
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
  return S;
}

int main() {
  vector<point> p;
  p.emplace_back(0, 0);
  p.emplace_back(1, 0);
  p.emplace_back(2, 0);
  p.emplace_back(1, 1);
  vector<point> ret = ConvexHull(p);
  for(auto it : ret) {
    cout << it.first << ' ' << it.second << endl;
  }
}