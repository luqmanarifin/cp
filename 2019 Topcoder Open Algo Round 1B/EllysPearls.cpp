#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

const int N = 55;

int dp[N][1 << 15][15];
int last[N][15];

void upd(int& at, int val) {
  at = min(at, val);
}

class EllysPearls {
public:
  int getMin(int n, int m, vector<int> a) {
    for (int i = 0; i < n; i++) a[i]--;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < (1 << m); j++) {
        for (int k = 0; k < m; k++) {
          dp[i][j][k] = inf;
        }
      }
    }
    memset(last, -1, sizeof(last));
    for (int j = 0; j < 15; j++) {
      for (int i = 1; i < n; i++) {
        last[i][j] = last[i-1][j];
        if (j == a[i-1]) {
          last[i][j] = i - 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      // bikin baru
      upd(dp[i][1 << a[i]][a[i]], i);

      // ngelanjutin last
      if (last[i][a[i]] != -1) {
        for (int j = 0; j < (1 << m); j++) {
          if (j & (1 << a[i])) {
            int add = i - last[i][a[i]] - 1;
            upd(dp[i][j][a[i]], dp[last[i][a[i]]][j][a[i]] + add);
          }
        }
      }

      // tambah mask yg lain
      for (int j = 0; j < (1 << m); j++) {
        if (j & (1 << a[i])) {
          int mask_bef = (j ^ (1 << a[i]));
          for (int col_bef = 0; col_bef < m; col_bef++) {
            if (col_bef == j) continue;
            if (last[i][col_bef] == -1) continue;
            int add = i - last[i][col_bef] - 1;
            upd(dp[i][j][a[i]], dp[last[i][col_bef]][mask_bef][col_bef] + add);
          }
        }
      }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << m); j++) {
        for (int k = 0; k < m; k++) {
          upd(ans, dp[i][j][k] + n - i - 1);
        }
      }
    }
    return ans;
  }
};

// int main() {
//   // int l = 0;
//   // int r = 0;

//   // EllysPearls EllysPearls;
//   // cout << EllysPearls.getMin() << endl;

//   return 0;
// }
