#include <bits/stdc++.h>

using namespace std;

long long ans;
int bef, a;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    ans = 0;
    bef = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a);
      if(bef < a) {
        ans += a - bef;
      }
      bef = a;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
