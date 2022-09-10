#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 69;

vector<pair<int, int>> edge[N];

// node i height nya berapa
int h[N];
pair<int, int> p[N];

// di posisi lca node keberapa
int t, at[N * 3];

// node i posisinya dimana
int pos[N * 3];

// sparse table
int tab[N * 3][20];
int lg[N * 3];

void dfs(int now, int prev) {
  pos[now] = t;
  at[t++] = now;
  h[now] = h[prev] + 1;
  for(auto it : edge[now]) {
    if(it.first == prev) {
      p[now] = it;
      continue;
    }
    dfs(it.first, now);
    pos[now] = t;
    at[t++] = now;
  }
}

void build() {
  dfs(1, 0);
  for(int i = 0; i < t; i++) {
    tab[i][0] = i;
  }
  for(int j = 1; (1 << j) <= t ; j++) {
    for(int i = 0; i + (1 << j) <= t; i++) {
      if(h[at[tab[i][j - 1]]] < h[at[tab[i + (1 << (j - 1))][j - 1]]]) {
        tab[i][j] = tab[i][j - 1];
      } else {
        tab[i][j] = tab[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

int rmq(int i, int j) {
  int logg = lg[j - i + 1];
  return h[at[tab[i][logg]]] < h[at[tab[j-(1<<logg)+1][logg]]]? tab[i][logg] : tab[j-(1<<logg)+1][logg];
}

int lca(int u, int v) {
  return at[rmq(min(pos[u], pos[v]), max(pos[u], pos[v]))];
}


// input
vector<pair<int, int>> e[N];
int par[N], cnt[N], flag[N], U[N], V[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void init(int n) {
  t = 0;
  for (int i = 0; i <= n; i++) {
    h[i] = 0;
    edge[i].clear();
    at[i] = 0;
    pos[i] = 0;
    e[i].clear();
    par[i] = i;
  }
}

int main() {
  for(int i = 0; (1 << i) < 3 * N; i++) {
    lg[1 << i] = i;
  }
  for(int i = 1; i < 3 * N; i++) {
    if(lg[i]) continue;
    lg[i] = lg[i - 1];
  }

  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);

    init(n);

    vector<tuple<int, int, int>> rem; // u - v - i

    for (int i = 0; i < m; i++) {
      cnt[i] = flag[i] = 0;
      int u, v;
      scanf("%d %d", &u, &v);
      e[u].emplace_back(v, i);
      e[v].emplace_back(u, i);
      U[i] = u; V[i] = v;
      if (find(u) != find(v)) {
        merge(u, v);
        edge[u].emplace_back(v, i);
        edge[v].emplace_back(u, i);
      } else {
        // printf("put rem idx %d\n", i);
        rem.emplace_back(u, v, i);
      }
    }
    // printf("rem size %d\n", rem.size());
    build();

    vector<vector<int>> path; // 0-1-2 : index edge
    path.resize(rem.size());
    for (int i = 0; i < rem.size(); i++) {
      int u, v, idx;
      tie(u, v, idx) = rem[i];
      int root = lca(u, v);

      int now = u;
      while (now != root) {
        path[i].push_back(p[now].second);
        cnt[p[now].second]++;
        now = p[now].first;
      }

      now = v;
      while (now != root) {
        path[i].push_back(p[now].second);
        cnt[p[now].second]++;
        now = p[now].first;
      }
    }
    // for (int i = 0; i < m; i++) printf("cnt %d %d\n", i, cnt[i]);
    // smallest - i - index edge
    vector<tuple<int, int, int>> res;
    vector<vector<pair<int, int>>> bank;  // cnt how much - index edge
    bank.resize(rem.size());
    for (int i = 0; i < rem.size(); i++) {
      int smallest = 1e9, at = -1;
      bank[i].emplace_back(-1, get<2>(rem[i]));
      for (int j = 0; j < path[i].size(); j++) {
        auto it = path[i][j];
        bank[i].emplace_back(cnt[it], it);
        if (cnt[it] < smallest) {
          smallest = cnt[it];
          at = it;
        }
      }
      sort(bank[i].begin(), bank[i].end());
      // printf("can %d %d %d\n", smallest, i, at);
      res.emplace_back(smallest, i, at);
    }
    for (int i = 0; i <= n; i++) par[i] = i;
    sort(res.begin(), res.end());
    for (auto x : res) {
      int smallest, i, at;
      tie(smallest, i, at) = x;
      for (auto it : bank[i]) {
        if (flag[it.second]) continue;
        if (find(U[it.second]) == find(V[it.second])) continue;
        merge(U[it.second], V[it.second]);
        flag[it.second] = 1;
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      printf("%d", flag[i]);
    }
    printf("\n");
  }

  return 0;
}
