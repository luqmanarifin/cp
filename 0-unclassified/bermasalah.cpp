#include <bits/stdc++.h>

using namespace std;

int a[10005];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += (a[i] * n < sum);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
