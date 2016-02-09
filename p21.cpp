#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h, a, num;
  scanf("%d %d %d %d", &n, &h, &a, &num);
  int w = h * num;
  for(int i = 1; n > 0 && w > 0; i++) {
    w -= n;
    if(w <= 0) {
      printf("%d\n", i);
      return 0;
    }
    int rem = w / h + (w % h? 1 : 0);
    n -= a * rem;
  }
  puts("-1");
  return 0;
}
