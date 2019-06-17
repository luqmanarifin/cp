#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int inf = 1e9;

int dp[N][N][2];
char s[N];
int end[N], mid[N];

int pre(int i) {
  if (s[i] != '(') {
    end[i] = i;
    return i;
  }
  int val = pre(i + 1);
  mid[i] = val + 1;
  val = pre(mid[i] + 1);
  end[i] = val + 1;
  return end[i];
}

int dfs(int l, int r, int val) {
  if (dp[l][r][val] != -1) return dp[l][r][val];
  int& ans = dp[l][r][val];
  if (l == r) {
    if (s[l] == '0' || s[l] == '1') {
      ans = 
    } else {

    }
    return ans;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j][0] = dp[i][j][1] = -1;
      }
    }
    scanf("%s", s);
    int n = strlen(s);
    assert(pre(0) == n - 1);
    printf("%d\n", min(dfs(0, n - 1, 0), dfs(0, n - 1, 1)));
  }

  return 0;
}
