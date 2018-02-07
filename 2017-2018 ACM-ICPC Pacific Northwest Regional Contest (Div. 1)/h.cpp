#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

typedef pair<long long, long long> line;

vector<line> hull[N];
int p[N];
vector<tuple<int, int, int, int> > edges;
bool isbad(line a, line b, line c) {
  return ((b.first-c.first) * (b.second-a.second) >= (a.first-b.first) * (c.second-b.second));
}

long long get(line l, long long x) {
  return l.first * x + l.second;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a; --b;
    edges.emplace_back(c, d, a, b);
  }
  hull[0].emplace_back(0, 0);
  sort(edges.begin(), edges.end());
  priority_queue<tuple<int, int, line> > pq;
  for (int i = 0; i < m; ++i) {
    int a, b, s, e;
    tie(s, e, a, b) = edges[i];
    while (!pq.empty()) {
      line nl;
      int t, u;
      tie(t, u, nl) = pq.top();
      t = -t;
      if (t > s) break;
      pq.pop();
      int sz;
      while ((sz = hull[u].size()) >= 2 && isbad(hull[u][sz-2], hull[u][sz-1], nl)) hull[u].pop_back();
      hull[u].push_back(nl);
    }
    if (hull[a].empty()) continue;
    int le = 0, ri = hull[a].size() - 1;
    while (le < ri) {
      int mid = (le + ri) >> 1;
      if (get(hull[a][mid], s) >= get(hull[a][mid+1], s))
        le = mid+1;
      else
        ri = mid;
    }
    long long cur = get(hull[a][le], s) + 1LL * s * s;
    line nl = make_pair(-2 * e, cur + 1LL * e * e);
    pq.emplace(-e, b, nl);
  }
  while (!pq.empty()) {
    line nl;
    int t, u;
    tie(t, u, nl) = pq.top();
    t = -t;
    pq.pop();
    int sz;
    while ((sz = hull[u].size()) >= 2 && isbad(hull[u][sz-2], hull[u][sz-1], nl)) hull[u].pop_back();
    hull[u].push_back(nl);
  }
  long long ans = 1e18;
  for (auto it : hull[n-1]) {
    long long e = -it.first/2, c = it.second;
    ans = min(ans, c - e * e);
  }
  cout << ans << endl;
  return 0;
}
