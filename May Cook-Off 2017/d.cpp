#include <bits/stdc++.h>

using namespace std;

const long long p[] = {2, 89, 13};
const long long mod = 1e9 + 7;
const int N = 1e6 + 5;

long long power[N][3];
long long h[N][3];
int cnt[N];

bool equal(int l, int r) {
  bool same = 1;
  for (int i = 0; i < 3; i++) if (h[l][i] != h[r][i]) same = 0;
  return same;
}

int main() {
  for (int j = 0; j < 3; j++) {
    power[0][j] = 1;
    for (int i = 1; i < N; i++) {
      power[i][j] = power[i-1][j] * p[j] % mod;
    }
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 3; j++) h[i][j] = h[i-1][j];
    
    int u, v;
    scanf("%d %d", &u, &v);
    if (cnt[u] % 2) {
      for (int j = 0; j < 3; j++) {
        h[i][j] -= power[u][j];
      }
    } else {
      for (int j = 0; j < 3; j++) {
        h[i][j] += power[u][j];
      }
    }
    if (cnt[v] % 2) {
      for (int j = 0; j < 3; j++) {
        h[i][j] -= power[v][j];
      }
    } else {
      for (int j = 0; j < 3; j++) {
        h[i][j] += power[v][j];
      }
    }
    for (int j = 0; j < 3; j++) {
      h[i][j] %= mod;
      if (h[i][j] < 0) h[i][j] += mod;
    }
    cnt[u] ^= 1;
    cnt[v] ^= 1;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    puts(equal(l-1, r)? "Yes" : "No");
  }
  return 0;
}
