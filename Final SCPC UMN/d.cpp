
#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const double eps = 1e-9;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, h;
    scanf("%d %d", &n, &h);
    n++;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    bool found = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        bool ok = 1;
        double d = (double) (a[j]-a[i])/(j-i);
        for (int k = 0; k < n; k++) {
          double lim_bawah = a[i]+(k-i)*d;
          double lim_atas = lim_bawah + h;
          if (lim_bawah + eps < a[k]) ok = 0;
          if (lim_atas > b[k] + eps) ok = 0;
        }
        if (ok) found = 1;

        ok = 1;
        d = (double) (b[j]-b[i])/(j-i);
        for (int k = 0; k < n; k++) {
          double lim_atas = b[i]+(k-i)*d;
          double lim_bawah = lim_atas - h;
          if (lim_bawah + eps < a[k]) ok = 0;
          if (lim_atas > b[k] + eps) ok = 0;
        }
        if (ok) found = 1;
      }
    }
    printf("Case #%d: %s\n", tt, found? "Ya" : "Tidak");
  }
  return 0;
}
