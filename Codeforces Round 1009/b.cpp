#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long now = -1;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (now == -1) {
        now = v;
      } else {
        now = now + v - 1;
      }
    }
    printf("%lld\n", now);
  } 

  return 0;
}
