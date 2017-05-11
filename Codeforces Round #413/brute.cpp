#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int b[N], c[N];
char f[N];

int main() {
  int n, C, D;
  scanf("%d %d %d", &n, &C, &D);
  for (int i = 0; i < n; i++) scanf("%d %d %c", b + i, c + i, f + i);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (f[i] == 'C' && f[j] == 'C' && c[i] + c[j] <= C) {
        ans = max(ans, b[i] + b[j]);
      } else if (f[i] == 'D' && f[j] == 'D' && c[i] + c[j] <= D) {
        ans = max(ans, b[i] + b[j]);
      } else if (f[i] == 'C' && f[j] == 'D' && c[i] <= C && c[j] <= D) {
        ans = max(ans, b[i] + b[j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
