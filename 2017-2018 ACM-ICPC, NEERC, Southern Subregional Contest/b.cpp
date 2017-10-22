#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> g[N], h[N];
int din[N], dout[N];
int n, m, k, r[N];
int ma[N], mi[N];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", r+i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    h[v].push_back(u);
    dout[u]++;
    din[v]++;
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (din[i] == 0)
      st.push(i);
  }
  vector<int> topo;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : g[v]) {
      din[u]--;
      if (din[u] == 0)
        st.push(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] == 0)
      ma[i] = k, mi[i] = 1;
    else
      ma[i] = mi[i] = r[i];
  }
  if (topo.size() != n) {
    puts("-1");
    return 0;
  }
  for (int v : topo) {
    for (int u : g[v]) {
      ma[u] = min(ma[u], ma[v]-1);
    }
  }
  for (int i = n-1; i >= 0; i--) {
    int v = topo[i];
    for (int u : g[v])
      mi[v] = max(mi[v], mi[u]+1);
  }
  //for (int i = 1; i <= n; i++)
    // cerr << i << " " << mi[i] << " " << ma[i] << endl;
  for (int i = 1; i <= n; i++) {
    if (ma[i] < mi[i]) {
      puts("-1");
      return 0;
    }
  }
//  cerr << "hallo " << endl;
  set<int> col;
  for (int i = 1; i <= k; i++) {
    col.insert(i);
  }
  set<pair<int, int> > sst;
  for (int i = 1; i <= n; i++)
    if (dout[i] == 0) {
      sst.insert(make_pair(ma[i], i));
    }
  while (!sst.empty()) {
    auto it = sst.begin();
    int v = it->second;
    sst.erase(it);
    r[v] = mi[v];
    for (int u : g[v]) {
      r[v] = max(r[v], r[u]+1);
    }
    auto rm = col.lower_bound(r[v]);
    if (rm != col.end() && *rm <= ma[v]) {
      r[v] = *rm;
    }
//    cerr << v << " " << r[v] << endl;
    col.erase(r[v]);
    for (int u : h[v]) {
      dout[u]--;
      if (dout[u] == 0)
        sst.insert(make_pair(ma[u], u));
    }
  }
//  for (int v : col)
    // cerr << " h " << v << endl;
  if (!col.empty())
    puts("-1");
  else {
    for (int i = 1; i <= n; i++)
      printf("%d%c", r[i], i == n ? '\n' : ' ');
  }
  return 0;
}
