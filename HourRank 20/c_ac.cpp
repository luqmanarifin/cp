#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> edge[N];
vector<int> pre;
int rmq[2 * N][20], h[N], urut[N], cnt, lef[N], rig[N];

int ans[N], a[N];

vector<int> adj[N];
int sub[N];

void dfs(int now, int bef) {
  lef[now] = rig[now] = pre.size();
  pre.push_back(now);
  if (bef >= 0) h[now] = h[bef] + 1;
  urut[now] = ++cnt;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    rig[now] = pre.size();
    pre.push_back(now);
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return (h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g]);
}

bool ancestor(int u, int v) {
  int root = lca(u, v);
  return root == u || root == v;
}

void build_sub(int now) {
  for (auto it : adj[now]) {
    build_sub(it);
    sub[now] += sub[it];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  edge[0].push_back(1);
  dfs(0, -1);
  for (int i = 0; i < pre.size(); i++) rmq[i][0] = pre[i];
  for (int j = 1; (1 << j) <= pre.size(); j++) {
    for (int i = 0; i+(1<<j) <= pre.size(); i++) {
      if (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]) {
        rmq[i][j] = rmq[i][j-1];
      } else {
        rmq[i][j] = rmq[i+(1<<(j-1))][j-1];
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    vector<pair<int, int>> aa, can;   // priority - node
    scanf("%d", &k);
    for (int i = 0; i <= k; i++) ans[i] = 0;
    for (int i = 0; i < k; i++) {
      scanf("%d", a + i);
      aa.emplace_back(urut[a[i]], a[i]);
    }
    sort(aa.begin(), aa.end());
    for (int i = 1; i < aa.size(); i++) {
      int mid = lca(aa[i-1].second, aa[i].second);
      can.emplace_back(urut[mid], mid);
    }
    for (auto it : aa) can.push_back(it);
    can.emplace_back(0, 0);
    sort(can.begin(), can.end());
    can.resize(distance(can.begin(), unique(can.begin(), can.end())));
    
    stack<int> st;
    st.push(0);
    for (int i = 1; i < can.size(); i++) {
      int now = can[i].second;
      //printf("%d ", now);
      while (!ancestor(st.top(), now)) st.pop();
      adj[st.top()].push_back(now);
      st.push(now);
    }
    //printf("\n");
    
    /*
    for (auto it : can) {
      for (auto kid : edge[it.second]) {
        printf("%d %d\n", it.second, kid);
      }
    }
    */
    
    for (int i = 0; i < k; i++) sub[a[i]] = 1;
    build_sub(0);
    for (auto it : can) {
      int now = it.second;
      for (auto kid : adj[now]) {
        ans[sub[kid]] += h[kid] - h[now];
      }
    }
    ans[0] = n;
    for (int i = 1; i <= k; i++) ans[0] -= ans[i];
    for (int i = 0; i <= k; i++) printf("%d ", ans[i]); printf("\n");
  
    for (auto it : can) {
      adj[it.second].clear();
      sub[it.second] = 0;
    }
  }
  
  return 0;
}
