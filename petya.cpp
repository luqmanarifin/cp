#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int last[N];

int main() {
  memset(last, -1, sizeof(last));
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = 0;
    for(int d = 1; d * d <= x; d++) {
      if(x % d == 0) {
        if(last[d] < i - y) {
          ans++;
        }
        if(last[x / d] < i - y && d * d != x) {
          ans++;
        }
        last[d] = last[x / d] = i;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
