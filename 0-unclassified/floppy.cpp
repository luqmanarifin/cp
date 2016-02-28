#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int k, n;
    scanf("%d %d", &k, &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d %d", a + i, b + i);
    }
    b[0] = 0;
    bool ada = 0;
    for(int s = 0; s <= k; s++) {
      int d = 1;
      int now = s;
      bool good = 1;
      for(int i = 1; i <= n; i++) {
        if(i > 1) {
          int dif = a[i] - b[i - 1];
          if(dif % 2) {
            d *= -1;
          }
        }
        now += d * (b[i] - a[i]);
        if(now < 0 || now > k) {
          good = 0;
          break;
        }
        if(now == 0 || now == k) {
          d *= -1;
        }
      }
      if(good) {
        ada = 1;
        break;
      }
    }
    if(!ada) {
      puts("impossible");
      return 0;
    }
  }
  puts("possible");
  return 0;
}
