#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long mod = 1e9 + 7;

int par[N];
bool done[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i + k <= n; i++) {
    for (int j = 0; j < k; j++) {
      merge(i + j, i + k - 1 - j);
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    if (!done[find(i)]) {
      done[find(i)] = 1;
      ans = ans * m % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
