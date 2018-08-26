#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int BIG = 2e6 + 5;
const long long mod = 1e9 + 7;

int par[N], sz[N];
long long fact[BIG], ifact[N];
bool done[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < BIG; i++) {
    fact[i] = fact[i - 1] * i % mod;
    // ifact[i] = inv(fact[i]);
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) par[i] = i;

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      merge(a, b);
    }
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i <= n; i++) {
      sz[find(i)]++;
    }
    int comp = 0;
    long long ans = 1;
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
      int root = find(i);
      if (!done[root]) {
        // printf("%d root %d\n", i, root);
        long long ada = sz[root] * (sz[root] - 1) / 2;
        // printf("size %d ada %lld\n", sz[root], ada);
        if (ada > 0) {
          // printf("JANCOK WKWK ada %lld\n", ada);
          comp++;
        }
        ans = ans * fact[ada] % mod;
        done[root] = 1;
      }
    }
    // printf("comp %d\n", comp);
    ans = ans * fact[comp] % mod;
    printf("Kasus #%d: %lld\n", tt, ans);
  }

  return 0;
}
