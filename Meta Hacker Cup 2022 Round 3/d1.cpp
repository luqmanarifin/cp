#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const int N = 6e5 + 5;

ull coeff[N];

struct fenwick {
  fenwick() {}
  fenwick(int n) : n(n) {
    num.assign(n, 0);
  }
  void add(int i, ull val) {
    for (; i < n; i |= i + 1) {
      num[i] += val;
    }
  }
  ull find(int i) {
    ull ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += num[i];
    }
    return ret;
  }
  ull find(int l, int r) {
    return find(r) - find(l - 1);
  }
  vector<ull> num;
  int n;
};

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

bool good[N];
int num_good, tot_good;

int par[N];
vector<int> el[N];
int n, m, k;
int col[N];

fenwick* fen;

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

int merge(int u, int v) {
  // printf("merge %d %d\n", u, v);
  u = find(u);
  v = find(v);
  // printf("jadi merge %d %d\n", u, v);
  if (el[u].size() > el[v].size()) {
    swap(u, v);
  }
  // puts("before update value");
  for (auto it : el[u]) {
    // transfer
    el[v].push_back(it);

    // update value
    fen->add(it, -coeff[u]);
    fen->add(it, +coeff[v]);
  }
  // puts("before check good");
  for (auto it : el[u]) {
    // check good
    int gol = it / k;
    if (good[gol]) continue;
    int ada = min(k, n - gol * k);
    if (fen->find(k * gol, k * gol + ada - 1) == coeff[v] * ada) {
      good[gol] = 1;
      num_good++;
    }
  }
  // puts("finish merge");
  par[u] = v;
  return v;
}

int main() {
  for (int i = 0; i < N; i++) {
    coeff[i] = rng();
  }
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(col, -1, sizeof(col));

    scanf("%d %d %d", &n, &m, &k);
    fen = new fenwick(n);
    num_good = 0;
    for (int i = 0; i < n; i++) {
      par[i] = i;
      el[i] = {i};
      col[i+1] = i;
      fen->add(i, coeff[i]);

      int gol = i / k;
      int ada = min(k, n - gol * k);
      good[gol] = 0;
      if (ada == 1) {
        good[gol] = 1;
        num_good++;
      }
    }
    
    tot_good = (n - 1) / k + 1;
    // puts("here fine");

    int ans = (num_good == tot_good? 0 : -1);
    for (int i = 1; i <= m; i++) {
      // printf("second %d\n", i);
      int u, v;
      scanf("%d %d", &u, &v);
      if (col[u] == -1) continue;
      if (col[v] == -1) {
        col[v] = col[u];
        col[u] = -1;
        continue;
      }
      col[v] = merge(col[u], col[v]);
      col[u] = -1;
      if (num_good == tot_good && ans == -1) {
        ans = i;
      }
      // printf("at %d: ", i); for (int j = 0; j < n; j++) printf("%d ", find(j)); printf("\n");
      // for (int j = 0; j < tot_good; j++) printf("%d ", good[j]); printf("\n");
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
