#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

#define ull unsigned long long

ull a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n + m + 1; i++) {
      scanf("%llu", a + i);
    }
    ull ans = a[0];
    for(int i = 1; i <= n; i++) {
      ans &= a[i];
    }
    for(int i = n + 1; i <= n + m; i++) {
      ans |= a[i];
    }
    printf("%llu\n", ans);
  }
  
  return 0;
}
