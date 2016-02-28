#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    while(n--) {
      int a;
      scanf("%d", &a);
      sum += a;
    }
    printf("Case #%d: ", tt);
    if(sum <= 16000) puts("16GB");
    else if(sum <= 32000) puts("32GB");
    else if(sum <= 64000) puts("64GB");
    else puts("128GB");
  }
  
  return 0;
}
