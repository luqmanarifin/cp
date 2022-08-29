#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int mx = 0, p = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (a[i] > mx) {
        mx = a[i];
        p = i;
      }
    }
    bool good = 1;
    for (int i = 1; i <= p; i++) {
      if (a[i - 1] > a[i]) {
        good = 0;
      }
    }
    for (int i = p + 1; i < n; i++) {
      if (a[i - 1] < a[i]) {
        good = 0;
      }
    }
    puts(good? "YES" : "NO");
  }

  return 0;
}
