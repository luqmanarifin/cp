#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, s;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
      int sum = 0, mini = N;
      for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
          sum += a[i];
          mini = min(mini, a[i]);
        }
      }
      if(sum >= s && sum - mini < s) {
        ans = max(ans, __builtin_popcount(mask));
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
