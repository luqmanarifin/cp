#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int par[N];

bool done[N];
vector<int> st;
int rmq[N << 2][20], h[N];
int lef[N << 2], rig[N << 2];

int find(int u) {
  return par[u] = par[u] == u? u : find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void dfs(int now) {
  done[now] = 1;
  lef[now] = rig[now] = st.size();
  st.push_back(now);
  for (auto it : edge[now]) {
    h[it.first] = h[now] + 1;
    dfs(it.first);
    rig[now] = st.size();
    st.push_back(now);
  }
}

int lca(int u, int v) {
  if (find(u) != find(v)) return -1;
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

vector<int> answer;
vector<pair<int, int>> ask[N][2];    // tanya siapa - ID berapa
int ans[N];

int t[N], u[N], v[N];
vector<int> token[N];

int entry(int child, int dad, int type) {
  int ret = answer.size();
  ask[child][type].emplace_back(dad, ret);
  answer.push_back(0);
  return ret;
}

set<int> anc;

void solve(int now, int type) {
  done[now] = 1;
  for (auto it : ask[now][type]) {
    answer[it.second] = anc.count(it.first);
  }
  anc.insert(now);

  for (auto it : edge[now]) {
    if (type != it.second) continue;
    solve(it.first, type);
  }
  anc.erase(now);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p, t;
    scanf("%d %d", &p, &t);
    if (p != -1) {
      edge[p].emplace_back(i, t);
      merge(i, p);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (done[i]) continue;
    dfs(i);
  }
  for (int i = 0; i < st.size(); i++) rmq[i][0] = st[i];
  for (int j = 1; (1 << j) <= st.size(); j++) {
    for (int i = 0; i + (1 << j) <= st.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    ans[i] = 1;
    scanf("%d %d %d", t + i, u + i, v + i);
    t[i]--;

    if (u[i] == v[i]) {
      ans[i] = 0;
      continue;
    }

    if (t[i] == 0) {
      token[i].push_back(entry(v[i], u[i], 0));
    } else {
      int root = lca(u[i], v[i]);
      if (root != -1) {
        if (v[i] == root) {
          ans[i] = 0;
        } else if (u[i] == root) {
          token[i].push_back(entry(v[i], root, 1));
        } else {
          token[i].push_back(entry(v[i], root, 1));
          token[i].push_back(entry(u[i], root, 0));
        }
      } else {
        ans[i] = 0;
      }
    }
  }

  for (int j = 0; j < 2; j++) {
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
      if (done[i]) continue;
      solve(i, j);
    }
  }
  for (int i = 0; i < q; i++) {
    for (auto it : token[i]) {
      ans[i] &= answer[it];
    }
    puts(ans[i]? "YES" : "NO");
  }
  return 0;
}
