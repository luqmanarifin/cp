#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int x[N], y[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          if (a - x[j] < x[i] && b - y[j] < y[i]) {

          } else if (x[i] <= a && x[j] <= a && y[i] <= b && y[j] <= b) {
            ans = max(ans, x[i] * y[i] + x[j] * y[j]);
          }
          swap(x[j], y[j]);
        }
        swap(x[i], y[i]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
