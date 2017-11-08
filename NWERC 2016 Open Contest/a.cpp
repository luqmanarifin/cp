#include <bits/stdc++.h>

using namespace std;

const int N = 45, M = 405;
const int inf = 1e8;

struct item {
  item() {}
  item(int r, int d) : r(r), d(d) {}
  int r;
  int d;
};

char s[N][M];
int dp[N][N][10][M];
int dpk[N][N][M];
item b[N][N][10][M];
int bk[N][N][M];
int n, m;

int cnt[N][10][M];

int count(int l, int r, int last, int dig) {
  return cnt[r][last][dig] - cnt[l - 1][last][dig];
}

int dfs(int l, int r, int last, int dig);
int dfs(int l, int r, int dig);

int dfs(int l, int r, int dig) {
  if (l >= r) return 0;
  int& ret = dpk[l][r][dig];
  if (ret != -1) return ret;
  int p = -1;
  ret = inf;
  for (int i = 0; i < 10; i++) {
    int cur = dfs(l, r, i, dig);
    //if (l == 1 && r == 3 && dig == 0) printf("%d %d\n", i, cur);
    if (cur < ret) {
      ret = cur;
      p = i;
    }
  }
  bk[l][r][dig] = p;
  return ret;
}

int dfs(int l, int r, int last, int dig) {
  if (l > r) return 0;
  if (dig == m) return 0;
  int& ret = dp[l][r][last][dig];
  if (l == r) {
    ret = 1 - count(l, r, last, dig);
    return ret;
  }
  if (ret != -1) return ret;
  ret = r - l + 1 - count(l, r, last, dig) + dfs(l, r, dig + 1);
  b[l][r][last][dig] = item(l - 1, -1);
  for (int i = l; i < r; i++) {
    for (int j = 0; j < last; j++) {
      int cur = dfs(l, i, j, dig) + r - i - count(i + 1, r, last, dig) + dfs(i + 1, r, dig + 1);
      if (cur < ret) {
        ret = cur;
        b[l][r][last][dig] = item(i, j);
      }
    }
  }
  return ret;
}

void change(int l, int r, int last, int dig);
void change(int l, int r, int dig);

void change(int l, int r, int last, int dig) {
  if (l > r) return;
  if (dig == m) return;
  //printf("%d %d %d %d\n", l, r, last, dig);
  if (l == r) {
    s[l][dig] = last;
    return;
  }
  for (int i = b[l][r][last][dig].r + 1; i <= r; i++) {
    s[i][dig] = last;
  }
  int i = b[l][r][last][dig].r;
  int j = b[l][r][last][dig].d;
  change(l, i, j, dig);
  change(i + 1, r, dig + 1);
}

void change(int l, int r, int dig) {
  if (l >= r) return;
  //printf("%d %d %d\n", l, r, dig);
  change(l, r, bk[l][r][dig], dig);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      s[i][j] -= '0';
      cnt[i][s[i][j]][j]++;
    }
  }
  for (int j = 0; j < m; j++) {
    for (int k = 0; k < 10; k++) {
      for (int i = 1; i <= n; i++) {
        cnt[i][k][j] += cnt[i - 1][k][j];
      }
    }
  }
  //cout << count(1, 1, 1, 0) << endl;
  memset(dp, -1, sizeof(dp));
  memset(dpk, -1, sizeof(dpk));
  dfs(1, n, 0);
  change(1, n, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", s[i][j]);
    }
    printf("\n");
  }
  return 0;

}