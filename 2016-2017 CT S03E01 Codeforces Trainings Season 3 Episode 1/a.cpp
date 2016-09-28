#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 1e9 + 7;
const long long MOD = 2e9 + 89;
const int N = 1e5 + 5;

long long power[N];
int a[N], b[N];

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = power[i - 1] * PRIME % MOD;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
      int j = i;
      long long va = power[a[i]], vb = power[b[i]];
      while (va != vb) {
        j++;
        va += power[a[j]];
        vb += power[b[j]];
        va %= MOD;
        vb %= MOD;
      }
      printf("%d-%d ", i, j);
      i = j;
    }
    printf("\n");
  }
  
  return 0;
}
