#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    bool can = 1;
    for (int i = 0; i < n - 2; i++) {
      if (a[i] > b[i]) {
        can = 0;
        break;
      }
      long long add = b[i] - a[i];
      a[i] += add;
      a[i + 1] += 2 * add;
      a[i + 2] += 3 * add;
    }
    for (int i = 0; i < n; i++) if (a[i] != b[i]) can = 0;
    puts(can? "TAK" : "NIE");
  }
  
  return 0;
}
