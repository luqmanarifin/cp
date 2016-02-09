#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int now = 0;
  n -= k;
  while(k--) {
    printf("%d %d ", now + 1, now + 2);
    now += 2;
  }
  while(n--) {
    printf("%d %d ", now + 2, now + 1);
    now += 2;
  }
  
  return 0;
}
