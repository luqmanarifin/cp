#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    long long ans = 1LL * n * (n + 1) / 2;
    for(int i = 1; i <= n; i *= 2) {
      ans -= 2LL * i;
    }
    printf("%I64d\n", ans);
  }
  
  return 0;
}
