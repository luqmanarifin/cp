#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;
    a %= 24;
    if(a < 0) a += 24;
    printf("Case #%d: %d%d\n", i, a / 10, a % 10);
  }
  
  return 0;
}
