#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> p, a;

int n;
char s[N];
int sum[N], dp[N];
bool used[N];

int get(int x, int y) {
  y++;
  if (x < 0) x = 0;
  if (x > y) return 0;
  return sum[y] - sum[x];
}

bool can(int x) {
  dp[0] = -1;
  for (int i = 0; i < p.size(); i++) {
    dp[i+1] = -1;
    if (get(dp[i]+1, p[i]-x-1) == 0)
      dp[i+1] = max(dp[i+1], p[i]);
    if (get(dp[i]+1, p[i]-1) == 0)
      dp[i+1] = max(dp[i+1], p[i]+x);
    if (i) {
      if (get(dp[i-1]+1, p[i]-x-1) == 0)
        dp[i+1] = max(dp[i+1], p[i-1] + x);
    }
  }
  return dp[p.size()] >= a.back();
}

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    sum[i+1] = sum[i];
    if (s[i] == 'P')
      p.push_back(i);
    else if (s[i] == '*')
      a.push_back(i), sum[i+1]++;
  }
  if (p.size() == 1) {
    pair<int, int> le = {sum[p[0]] - sum[0], -max(p[0]-a[0], 0)}, ri = {sum[n] - sum[p[0]], -max(a.back() - p[0], 0)};
    if (le < ri)
      swap(le, ri);
    printf("%d %d\n", le.first, -le.second);
    return 0;
  }
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d %d\n", (int)a.size(), l);
   return 0;
}