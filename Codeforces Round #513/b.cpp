#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int inf = 1e9;

int dp[N][2];
vector<int> a;

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  long long n;
  scanf("%lld", &n);
  while (n) {
    a.push_back(n % 10);
    n /= 10;
  }
  for (int i = 0; i < N; i++) {
    dp[i][0] = dp[i][1] = -inf;
  }
  dp[0][0] = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int add = 0; add <= 10; add += 10) {
      for (int st = 0; st <= 1; st++) {
        int sum = add + a[i] - st;
        for (int j = 0; j <= min(9, sum); j++) {
          int k = sum - j;
          if (0 <= k && k <= 9) {
            upd(dp[i + 1][add / 10], dp[i][st] + j + k);
          }
        }
      }
    }
  }
  cout << dp[a.size()][0] << endl;
  return 0;
}
