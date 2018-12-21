#include <bits/stdc++.h>

using namespace std;

const int C = 27, L = 63;
const int N = 1e6 + 6;
const long long inf = 1e17;

char buffer[N];
string t[C];
long long dp[L][C];
int to[L][N];

int advance(int now, long long len) {
  for (int i = 0; i < L; ++i) {
    if (len & (1LL << i))
      now = to[i][now];
  }
  return now;
}

int find(int now, int depth, long long x) {
  if (depth == 0)
    return now;
  for (int i = 0; i < t[now].size(); ++i) {
    int nxt = t[now][i];
    if (x >= dp[depth-1][nxt]) {
      x -= dp[depth-1][nxt];
      continue;
    }
    return find(nxt, depth-1, x);
  }
  assert(false);
}

int main() {
  for (int i = 0; i < 27; ++i) {
    scanf("%s", buffer);
    t[i] = buffer;
    for (int j = 0; j < t[i].size(); ++j)
      t[i][j] -= 'a'-1;
  }
  for (int i = 0; i < 27; ++i)
    to[0][i] = t[i][0];
  for (int j = 0; j + 1 < L; ++j)
    for (int i = 0; i < 27; ++i) {
      to[j+1][i] = to[j][to[j][i]];
  }
  for (int j = 0; j < 27; ++j)
    dp[0][j] = 1;
  for (int i = 0; i + 1 < L; ++i) {
    for (int j = 0; j < 27; ++j) {
      dp[i+1][j] = 0;
      for (int k = 0; k < t[j].size(); ++k) {
        dp[i+1][j] += dp[i][t[j][k]];
        if (dp[i+1][j] > inf)
          dp[i+1][j] = inf;
      }
    }
  }
  long long K;
  scanf("%lld", &K);
  ++K;
  int now = 0;
  if (K > 60) {
    now = advance(now, K-60);
    K = 60;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    long long x;
    scanf("%lld", &x);
    --x;
    int res = find(now, K, x);
    printf("%c\n", char (res + 'a' - 1) );
  }
  return 0;
}