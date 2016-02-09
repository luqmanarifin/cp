#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    long long sum = 0, a, m;
    for(int i = 0; i < 5; i++) {
      scanf("%lld", &a);
      sum += a;
    }
    scanf("%lld", &m);
    printf("Case #%d: ", tt);
    if(sum >= m) {
      puts("0");
      continue;
    }
    if(sum <= 0) {
      puts("-1");
      continue;
    }
    for(int i = 0; ; i++) {
      if(sum * (1LL << i) >= m) {
        printf("%d\n", i);
        break;
      }
    }
  }
  
  return 0;
}
