#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a, b, n;
int ans[N];

int main() {
  scanf("%d %d %d", &a, &b, &n);
  int now = a % b;
  
  for(int it = 0; it < n; it++) {
    now = now * 10 % b;
    bool ada = 0;
    for(int i = 0; i <= 9; i++) {
      if((now + i) % b == 0) {
        ada = 1;
        ans[it] = i;
        now = (now + i) % b;
        break;
      }
    }
    if(!ada) {
      puts("-1");
      return 0;
    }
  }
  printf("%d", a);
  for(int i = 0; i < n; i++) {
    printf("%d", ans[i]);
  }
  return 0;
}
