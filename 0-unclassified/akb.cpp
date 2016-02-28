#include <bits/stdc++.h>

using namespace std;

int sum(int a) {
  int ret = 0;
  while(a > 0) {
    ret += a % 10;
    a /= 10;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case #%d: %d\n", tt, sum(a) * sum(b));
  }
  
  return 0;
}
