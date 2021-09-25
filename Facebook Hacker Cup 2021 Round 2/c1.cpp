#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const int inf = 1e9;

vector<vector<int>> sum;
vector<string> s;
int n, m, k;

int find(int si, int ti, int j) {
  if (si > ti) return 0;
  if (ti > n) ti = n;
  if (si < 0) si = 0;
  return sum[ti][j] - (si? sum[si-1][j] : 0);
}

bool valid(int i, int j) {
  return 1 <= i && i <= n && 0 < j && j < m;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    sum.clear();
    s.clear();
    
    cin >> n >> m >> k;
    s = vector<string>(n + 1);
    sum = vector<vector<int>>(n + 1, vector<int>(m, 0));
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    for (int j = 0; j < m; j++) {
      for (int i = 1; i <= n; i++) {
        if (s[i][j] == 'X') sum[i][j] = 1;
        sum[i][j] += sum[i-1][j];
      }
    }
    int ans = inf;
    for (int i = 0; i <= n + 1; i++) {
      int cur = abs(i - k);
      for (int j = 0; j < m; j++) {
        if (i < k) {
          int car = find(i, n, j);
          int cap = n - k;
          if (car > cap) {
            cur++;
          } else {
            if (valid(i, j) && s[i][j] == 'X') {
              cur++;
            }
          }
        } else if (k < i) {
          int car = find(1, i, j);
          int cap = k - 1;
          if (car > cap) {
            cur++;
          } else {
            if (valid(i, j) && s[i][j] == 'X') {
              cur++;
            }
          }
        } else {
          cur += (s[i][j] == 'X');
        }
      }
      ans = min(ans, cur);
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
