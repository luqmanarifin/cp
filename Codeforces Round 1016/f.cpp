#include <bits/stdc++.h>

using namespace std;

const int N = 505;

bool same[N][N];
string a[N], b[N][N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> b[i][j];
        same[i][j] = (a[j] == b[i][j]);
      }
    }
    bool can = 1;
    for (int j = 0; j < n; j++) {
      bool found = 0;
      for (int i = 0; i < m; i++) {
        if (same[i][j]) {
          found = 1;
        }
      }
      if (!found) {
        can = 0;
        break;
      }
    }
    if (!can) {
      puts("-1");
      continue;
    }
    int best = 0;
    for (int i = 0; i < m; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (same[i][j]) {
          cur++;
        }
      }
      best = max(best, cur);
    }
    printf("%d\n", n + 2 * (n - best));
  }

  return 0;
}
