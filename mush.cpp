#include <bits/stdc++.h>

using namespace std;

long long a[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(a, 0, sizeof(a));
    int n;
    long long ans1 = 0, ans2 = 0;
    long long dif = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%I64d", &a[i]);
      if(i && a[i - 1] > a[i]) {
        ans1 += abs(a[i - 1] - a[i]);
        dif = max(dif, a[i - 1] - a[i]);
      }
    }
    long long now = 0;
    for(int i = 0; i < n - 1; i++) {
      ans2 += min(dif, a[i]);
    }
    printf("Case #%d: %I64d %I64d\n", tt, ans1, ans2);
  }
  
  return 0;
}
