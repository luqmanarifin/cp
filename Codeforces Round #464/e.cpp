
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long a[N], s[N];
int sz;

double get(int num) {
  long long tot = a[sz - 1] + (num > 1? s[num - 2] : 0);
  return (double) tot / num;
}

int main() {
  int q;
  scanf("%d", &q);
  double ans = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      a[sz] = x;
      s[sz] = (sz? s[sz - 1] : 0) + x;
      sz++;
      
      int l = 1, r = sz;
      while (r - l > 3) {
        int lf = l + (r - l) / 3;
        int rf = r - (r - l) / 3;
        if (get(lf) > get(rf)) {
          l = lf;
        } else {
          r = rf;
        }
      }
      for (int i = l; i <= r; i++) {
        //printf("get %d: %.15f\n", i, get(i));
        ans = max(ans, x - get(i));
      }
    } else {
      printf("%.15f\n", ans);
    }
  }
  return 0;
}
