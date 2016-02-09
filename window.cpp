#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2 * m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2 * m; j += 2) {
      if(a[i][j] || a[i][j + 1]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
