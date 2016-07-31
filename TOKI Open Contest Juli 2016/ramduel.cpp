#include <bits/stdc++.h>

using namespace std;

const int N = 305;

char sa[N], sb[N];
int to[N][N], dp[N][N], a[N][N];

void print(int k) {
  string random = "jancok";
  for (int i = 0; i < k; i++) {
    printf("%c", random[i % random.size()]);
  }
}

vector<int> 

void backtrack(int i, int j) {
  if (i == 0 && j == 0) return;
  int bi = to[i][j] / N;
  int bj = to[i][j] % N;
  backtrack(bi, bj);
  if (a[i][j]) printf("%c", sa[i - 1]);
}

int main() {
  scanf("%s %s", sa, sb);
  int n = strlen(sa);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      //if (dp[i][j]) printf("%d %d\n", i, j);
      if (sa[i] == sb[j]) {
        if (dp[i][j] + 1 > dp[i + 1][j + 1]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
          to[i + 1][j + 1] = i * N + j;
          a[i + 1][j + 1] = 1;
        }
      }
      if (dp[i][j] > dp[i + 1][j]) {
        dp[i + 1][j] = dp[i][j];
        to[i + 1][j] = i * N + j;
        a[i + 1][j] = 0;
      }
      if (dp[i][j] > dp[i][j + 1]) {
        dp[i][j + 1] = dp[i][j];
        to[i][j + 1] = i * N + j;
        a[i][j + 1] = 0;
      }
    }
  }
  if (dp[n][n] == 0) {
    print(n);
    printf("\n");
    return 0;
  }
  backtrack(n, n);
  print(n - dp[n][n]);
  printf("\n");
  return 0;
}
