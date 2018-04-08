#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> g[N];

long double f[N];
int cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
    f[i] = 0;
  }
  f[n-1] = 0;
  cnt[n-1] = 1;
  set<pair<long double, int> > st;
  st.insert(make_pair(f[n-1], n-1));
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    st.erase(it);
    for (int u : g[v]) {
      if (u == n-1) continue;
      if (cnt[u] != 0 && f[u] <= f[v]) continue;
      long double val = (f[u] * cnt[u] + f[v]);
      if (cnt[u] == 0)
        val += g[u].size();
      val /= cnt[u] + 1;
      if (cnt[u] == 0 || val < f[u]) {
        st.erase(make_pair(f[u], u));
        f[u] = val;
        ++cnt[u];
        st.insert(make_pair(f[u], u));
      }
    }
  }
  printf("%.20lf\n", (double)f[0]);
  return 0;
}
