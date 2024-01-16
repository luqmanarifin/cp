#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dig[4];
vector<vector<int>> top, down;
vector<string> s;
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> m >> k;
    k = min(k, n + m);
    int offset = k + 1;

    s.clear();
    for (int i = 0; i < n; i++) {
      string buf;
      cin >> buf;
      s.push_back(buf);
    }

    if (n > m) {
      vector<string> tmp;
      for (int j = 0; j < m; j++) {
        string buf;
        for (int i = 0; i < n; i++) {
          buf.push_back(s[i][j]);
        }
        tmp.push_back(buf);
      }
      s = tmp;
      swap(n, m);
    }

    int M = m + 2 * offset;
    for (int i = 0; i < 4; i++) {
      dig[i].assign(n, vector<int>(M, 0));
    }
    top.assign(n, vector<int>(m, 0));
    down.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = -offset; j < m + offset; j++) {
        dig[0][i][j+offset] = dig[3][i][j+offset] = (valid(i, j) && s[i][j] == '#');
        if (i > 0 && j + 1+offset < M) {
          dig[0][i][j+offset] += dig[0][i - 1][j + 1+offset];
        }
        if (i > 0 && j+offset > 0) {
          dig[3][i][j+offset] += dig[3][i - 1][j - 1+offset];
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = -offset; j < m + offset; j++) {
        dig[1][i][j+offset] = dig[2][i][j+offset] = (valid(i, j) && s[i][j] == '#');
        if (i + 1 < n && j + 1+offset < M) {
          dig[1][i][j+offset] += dig[1][i + 1][j + 1+offset];
        }
        if (i + 1 < n && j+offset > 0) {
          dig[2][i][j+offset] += dig[2][i + 1][j - 1+offset];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        top[i][j] = (s[i][j] == '#');
        if (i > 0) {
          top[i][j] += top[i-1][j];
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        down[i][j] = (s[i][j] == '#');
        if (i + 1 < n) {
          down[i][j] += down[i+1][j];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int atas = 0, bawa = 0;
      for (int j = 0; j < m; j++) {
        atas += top[i][j];
        if (valid(i - k - 1, j)) {
          atas -= top[i - k - 1][j];
        }
        int diag = dig[0][i][j - k - 1+offset];
        if (i - k - 1 >= 0) {
          diag -= dig[0][i - k - 1][j+offset];
        }
        atas -= diag;

        bawa += down[i][j];
        if (valid(i + k + 1, j)) {
          bawa -= down[i + k + 1][j];
        }
        diag = dig[1][i][j - k - 1+offset];
        if (i + k + 1 < n) {
          diag -= dig[1][i + k + 1][j+offset];
        }
        bawa -= diag;

        ans = max(ans, atas);
        ans = max(ans, bawa);
      }
    }
    for (int i = 0; i < n; i++) {
      int atas = 0, bawa = 0;
      for (int j = m - 1; j >= 0; j--) {
        bawa += down[i][j];
        if (valid(i + k + 1, j)) {
          bawa -= down[i + k + 1][j];
        }

        int diag = dig[2][i][j + k + 1+offset];
        if (i + k + 1 < n) {
          diag -= dig[2][i + k + 1][j+offset];
        }
        bawa -= diag;

        atas += top[i][j];
        if (valid(i - k - 1, j)) {
          atas -= top[i - k - 1][j];
        }

        diag = dig[3][i][j + k + 1+offset];
        if (i - k - 1 >= 0) {
          diag -= dig[3][i - k - 1][j+offset];
        }
        atas -= diag;

        ans = max(ans, atas);
        ans = max(ans, bawa);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
