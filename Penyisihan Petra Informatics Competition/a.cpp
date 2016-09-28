#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const int inf = 1e9;

string s[N];
int b[N][N];
int d[N][N];
int good[N][N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(b, 0, sizeof(b));
    memset(d, 0, sizeof(d));
    memset(good, 0, sizeof(good));
    
    int n, m;
    cin >> n >> m;
    n = 2 * n + 1;
    cin.ignore();
    for (int i = 0; i < n; i++) {
      getline(cin, s[i]);
    }
    for (int i = 0; i + 1 < n; i++) {
      for (int j = 0; j < m; j++) {
        d[i][j] = b[i][j];
      }
      int cur = -inf;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') cur = -inf;
        cur += (s[i][j] == '.');
        if (good[i][j]) cur = max(cur, b[i][j]);
        d[i][j] = max(d[i][j], cur);
      }
      cur = -inf;
      for (int j = m - 1; j >= 0; j--) {
        if (s[i][j] == '#') cur = -inf;
        cur += (s[i][j] == '.');
        if (good[i][j]) cur = max(cur, b[i][j]);
        d[i][j] = max(d[i][j], cur);
      }
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#' || s[i + 1][j] == '#') continue;
        if (j < s[i + 1].length())
        b[i + 1][j] = d[i][j] + (s[i + 1][j] == '.');
        good[i + 1][j] = 1;
      }
      //cout << s[i] << endl;
      //for (int j = 0; j < m; j++) printf("%d ", d[i][j]); printf("\n");
    }
    int best = 0;
    for (int j = 0; j < m; j++) {
      best = max(best, b[n - 1][j]);
    }
    printf("%d\n", best);
  }
  
  return 0;
}
