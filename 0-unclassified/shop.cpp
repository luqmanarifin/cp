#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

int a[N][2];
int b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int j = 0; j < 2; j++) {
    for(int i = 1; i < n; i++) {
      scanf("%d", &a[i][j]);
    }
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  for(int i = 1; i < n; i++) {
    a[i][0] += a[i - 1][0];
  }
  for(int i = n - 1; i >= 1; i--) {
    a[i][1] += a[i + 1][1];
  }
  int ans = inf;
  for(int i = 0; i + 1 < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int cur = b[i] + a[i][0] + a[i + 1][1];
      cur += b[j] + a[j][0] + a[j + 1][1];
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
