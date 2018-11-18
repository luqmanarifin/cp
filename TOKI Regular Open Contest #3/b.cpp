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

int dp[N][2], a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) scanf("%d", a + i);

  dp[1][0] = (a[0] != a[1]);
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i-1]) {
      dp[i][1] += dp[i-1][1];
    }
    if (a[i] != a[i-2]) {
      dp[i][1] += dp[i-1][0];
    }
    if (a[i-1] != a[i-2] && a[i] != a[i-1]) {
      dp[i][0] += dp[i-1][0];
    }
    // printf("%d %d\n", dp[i][0], dp[i][1]);
  }
  cout << dp[n][0] + dp[n][1] << endl;
  return 0;
}
