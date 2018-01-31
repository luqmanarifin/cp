#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char s[N][N];

int main() {
  int n, m, K;
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  long long ans = 0;
  if (K == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          ans++;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') continue;
        int k = j;
        while (k + 1 < m && s[i][k + 1] == s[i][k]) k++;
        int ada = k - j + 1;
        if (ada >= K) {
          ans += ada - K + 1;
        }
        j = k;
      }
    }
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (s[i][j] == '*') continue;
        int k = i;
        while (i + 1 < n && s[k + 1][j] == s[k][j]) k++;
        int ada = k - i + 1;
        if (ada >= K) {
          ans += ada - K + 1;
        }
        i = k;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
