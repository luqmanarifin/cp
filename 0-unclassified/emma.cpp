#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 2e9;

int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      a[i][0] = min(a[i][0], a[i][j]);
    }
  }
  int ans = -inf;
  for(int i = 0; i < n; i++) {
    ans = max(ans, a[i][0]);
  }
  cout << ans << endl;
  return 0;
}
