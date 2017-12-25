#include <bits/stdc++.h>

using namespace std;

int cnt[4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    
    int n;
    scanf("%d", &n);
    while (n--) {
      int v;
      scanf("%d", &v);
      cnt[v % 4]++;
    }
    int a = cnt[1], b = cnt[2], c = cnt[3];
    int ans = 0;
    
    int del = min(a, c);
    a -= del;
    c -= del;
    ans += del;
    
    del = b / 2;
    b -= del * 2;
    ans += del;
    
    if (a) {
      del = min(b, a / 2);
      b -= del;
      a -= 2 * del;
      ans += 2 * del;
      
      del = a / 4;
      a -= del * 4;
      ans += 3 * del;
    }
    if (c) {
      del = min(b, c / 2);
      b -= del;
      c -= 2 * del;
      ans += 2 * del;
      
      del = c / 4;
      c -= del * 4;
      ans += 3 * del;
    }
    if (a || b || c) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }

  return 0;
}
