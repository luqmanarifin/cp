#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
bool can[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
      can[i] = 0;
    }
    bool good = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        good = 0;
        break;
      }
      int j = (i + 1) % n;
      if (a[i] < b[i] && b[i] > b[j] + 1) {
        good = 0;
        break;
      }
    }
    puts(good? "YES" : "NO");
  }

  return 0;
}
