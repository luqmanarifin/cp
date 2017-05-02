#include <bits/stdc++.h>

using namespace std;

const int N = 11;
const int inf = 1e9;

int a[N];
vector<int> edge[N];
int val[1 << N];
int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int get(int mask, int i) {
  if (mask & (1 << i)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int mask = 1; mask < (1 << n) - 1; mask++) {
    val[mask] = inf;
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
      for (auto it : edge[i]) {
        if (get(mask, i) == get(mask, it) && get(mask, i)) {
          merge(i, it);
        }
      }
    }
    bool can = 1;
    int last = -1;
    for (int i = 0; i < n; i++) {
      int root = find(i);
      if (mask & (1 << i)) {
        if (last == -1) {
          last = root;
        } else {
          if (last != root) {
            can = 0;
            break;
          }
        }
      }
    }
    if (can) {
      val[mask] = 0;
      for (int i = 0; i < n; i++) if (get(mask, i)) val[mask] += a[i];
      //printf("can %d:  ", mask);
      //for (int i = 0; i < n; i++) printf("%d", get(mask, i)); printf("\n");
    }
  }
  long long ans = 0;
  for (int i = 1; i < (1 << n) - 1; i++) {
    for (int j = 1; j < (1 << n) - 1; j++) {
      if (val[i] == inf || val[j] == inf) continue;
      if ((i & j) == 0) {
        ans = max(ans, 1LL * val[i] * val[j]);
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
