#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int dp[N], size;

int get(int a) {
  if(dp[a] != -1) return dp[a];
  if(a <= size) return dp[a] = 1;
  return dp[a] = get(a / 2) + get(a / 2 + a % 2);
}

int main() {
  int n;
  scanf("%d %d", &n, &size);
  memset(dp, -1, sizeof(dp));
  cout << get(n) << endl;
  return 0;
}
