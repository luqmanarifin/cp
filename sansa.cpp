#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      long long cur = 1LL * (i + 1) * (n - i);
      if(cur % 2) {
        ans ^= a;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
