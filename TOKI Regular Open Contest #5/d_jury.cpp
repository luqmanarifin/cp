#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long dp[N][11];

long long solve(int d, int k) {
  if (dp[d][k] != -1) return dp[d][k];
  if (d == 0) {
    if (k <= 1) {
      return dp[d][k] = 1;
    } else {
      return dp[d][k] = 0;
    }
  }
  long long ret = 0;
  for (int i = 0; i <= k; i++) {
    ret += solve(d - 1, i) * solve(d - 1, k - i);
    ret %= mod;
  }
  return dp[d][k] = ret;
}

int main() {
  int d, k;
  scanf("%d %d", &d, &k);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 1;
  dp[1][0] = 2;
  for (int i = 2; i < N; i++) {
    dp[i][0] = (1 + dp[i-1][0] * dp[i-1][0]) % mod;
  }
  cout << solve(d - 1, k) << endl;

  return 0;
}
