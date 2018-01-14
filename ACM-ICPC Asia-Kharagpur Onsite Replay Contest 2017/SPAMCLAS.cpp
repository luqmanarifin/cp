#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int w[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, minx, maxx;
    scanf("%d %d %d", &n, &minx, &maxx);
    for (int i = 0; i < n; i++) scanf("%d %d", w + i, c + i);
    int a = 1, b = 0;
    for (int i = 0; i < n; i++) {
      a = (a * w[i]) % 2;
      b = (b * w[i] + c[i]) % 2;
    }
    int ans0 = 0, ans1 = 0;
    if (a == 0) {
      if (b == 0) {
        ans0 = maxx - minx + 1;
      } else {
        ans1 = maxx - minx + 1;
      }
    } else {
      int cnt = maxx - minx + 1;
      if (minx % 2 == 0) minx++;
      if (maxx % 2 == 0) maxx--;
      int odd = (minx > maxx? 0 : (maxx - minx) / 2 + 1);
      if (b == 0) {
        ans0 = cnt - odd;
        ans1 = odd;
      } else {
        ans0 = odd;
        ans1 = cnt - odd;
      }
    }
    printf("%d %d\n", ans0, ans1);
  }  

  return 0;
}
