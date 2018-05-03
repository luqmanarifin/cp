#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N][N];
pair<int, int> bef[N][N][N];

vector<int> ret;

void backtrack(int now, int i, int j) {
  if (now > 1) {
    backtrack(now - 1, bef[now][i][j].first, bef[now][i][j].second);
  }
  ret.push_back(i);
  ret.push_back(j);
}

class StablePairsDiv1 {
public:
  vector<int> findMaxStablePairs(int n, int c, int k) {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        dp[1][i][j] = i + j;
      }
    }
    for (int p = 1; p < k; p++) {
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (dp[p][i][j] == -1) continue;
          pair<int, int> b = make_pair(i, j);
          for (int ni = j + 1; j <= n; j++) {
            int nj = i + j + c - ni;
            if (nj > ni && dp[p + 1][ni][nj] < dp[p][i][j] + ni + nj) {
              dp[p + 1][ni][nj] = dp[p][i][j] + ni + nj;
              bef[p + 1][ni][nj] = b;
            }
          }
        }
      }
    }
    int pi = -1, pj = -1, ans = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (ans < dp[k][i][j]) {
          ans = dp[k][i][j];
          pi = i;
          pj = j;
        }
      }
    }
    if (ans == -1) return ret;
    backtrack(k, pi, pj);
    return ret;
  }
};

// int main() {
//   int l = 0;
//   int r = 0;

//   StablePairsDiv1 StablePairsDiv1;
//   cout << StablePairsDiv1.findMaxStablePairs() << endl;

//   return 0;
// }
