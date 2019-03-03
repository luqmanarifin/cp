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

const int N = 2005;
const long long mod = 1e9 + 7;

const long long inf = 2005;

long long dp[N][N];

void add(long long& at, long long val) {
  at += val;
  if (at >= mod) at -= mod;
}

int gcd(int a , int b)
{
  if(b==0) return a;
  a%=b;
  return gcd(b,a);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    add(dp[i][val], val);
    for (int bef = 1; bef < N; bef++) {
      add(dp[i][bef], dp[i-1][bef]);
      add(dp[i][gcd(bef, val)], 1LL * dp[i-1][bef] * val % mod);
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    add(ans, 1LL * i * dp[n][i] % mod);
  }
  cout << ans << endl;
  return 0;
}
