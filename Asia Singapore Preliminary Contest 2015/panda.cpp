#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, d;
map< long long, int > mp;
int x[N], nx, f[N], val[N];
vector< int > adj[N];
int ans;
stack< int > st;
vector< int > topo;

int main() {
  scanf("%d%d%d", &n, &m, &d);
  int cnt = 0;
  for(int i = 0; i< m; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    int na, nb;
    if(mp.count(a))
      na = mp[a];
    else
      mp[a] = na = cnt++;
    if(mp.count(b))
      nb = mp[b];
    else
      mp[b] = nb = cnt++;
    adj[na].push_back(nb);
    f[nb]++;
  }
  for(int i = 0; i<cnt; i++) {
    if(f[i] == 0)
      st.push(i);
  }
  while(!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for(int j = 0; j<adj[v].size(); j++) {
      int u = adj[v][j];
      f[u]--;
      if(f[u] == 0)
        st.push(u);
    }
  }
  for(int i = 0; i<topo.size(); i++)
    val[topo[i]] = i;
  nx = 0;
  ans = 0;
  for(int i = 0; i<n; i++) {
    long long a;
    scanf("%lld", &a);
    if(mp.count(a)) {
      int na = mp[a];
      x[nx++] = val[na];
    }
    else
      ans++;
  }
  int nf = 0; 
  for(int i = 0; i<nx; i++) {
    int p = lower_bound(f, f+nf, x[i])-f;
    f[p] = x[i];
    nf = max(p+1, nf);
  }
  ans += nx-nf+n-nf;
  printf("%d\n", ans);
  return 0;
} 