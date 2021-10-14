#include <bits/stdc++.h>

using namespace std;

const int LEN = 8e5 + 1;
const int offset = 4e5;
const int N = 20;

int cnt[N][LEN][2];
int dp[1 << N];

vector<string> a;
int sum[1 << N], lowest[N];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  a = vector<string>(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int now = 0, mn = 0;
    vector<bool> done(a[i].size() + 1, false);
    for (int j = 0; j < a[i].size(); j++) {
      if (a[i][j] == '(') {
        now++;
      } else {
        now--;
      }
      if (now < 0 && !done[-now]) {
        done[-now] = 1;
        cnt[i][offset + now + 1][1] = cnt[i][offset + now + 1][0];
      }
      mn = min(mn, now);
      cnt[i][offset + now][0]++;
    }
    sum[1 << i] = now;
    lowest[i] = mn;
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) {
        sum[mask | (1 << i)] = sum[mask] + sum[1 << i];
      }
    }
  }
  int ans = 0;
  dp[0] = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (dp[mask] == -1) continue;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) {
        if (sum[mask] + lowest[i] >= 0) {
          upd(dp[mask | (1 << i)], dp[mask] + cnt[i][offset - sum[mask]][0]);
        }
        upd(ans, dp[mask] + cnt[i][offset - sum[mask]][1]);
      }
    }
  }
  cout << max(ans, dp[(1 << n) - 1]) << endl;
  return 0;
}
