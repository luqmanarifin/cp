#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;
const int offset = N * N;

int dp[2][N][2*N*N + N];
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    tot += a[i];
  }
  vector<int> p;
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    p.push_back(b[i]);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  
  int bottle = 0;
  int sum = 0;
  for (int i = 0; i < p.size(); i++) {
    if (sum >= tot) break;
    sum += p[i];
    bottle++;
  }
  
  for (int j = 0; j < N; j++) {
    for (int k = 0; k < 2 * N * N + N; k++) {
      dp[0][j][k] = dp[1][j][k] = inf;
    }
  }
  dp[0][0][0] = 0;
  int st = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= bottle; j++) {
      for (int k = 0; k <= sum + N; k++) {
        dp[st^1][j+1][]
      }
    }
    for (int j = 0; j <= bottle; j++) {
      for (int k = 0; k <= sum; k++) {
        dp[st][j][k] = inf;
      }
    }
    st ^= 1;
  }
  printf("%d %d\n", bottle, ans);
  return 0;
}
