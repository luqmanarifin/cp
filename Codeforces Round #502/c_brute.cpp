#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> a) {
  vector<int> dp;
  dp.assign(a.size(), 0);
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int now = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        now = max(now, dp[j]);
      }
    }
    dp[i] = now + 1;
    ans = max(ans, dp[i]);
  }
  return ans;
}

int lcs(vector<int> a) {
  reverse(a.begin(), a.end());
  return lis(a);
}

int main() {
  vector<int> p = {3, 4, 1, 2};
  cout << lis(p) << endl;
  cout << lcs(p) << endl;
  for (int n = 1; n <= 10; n++) {
    vector<int> a;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) a[i] = i;
    int ans = 1e9;
    vector<int> tmp;
    do {
      int cur = lis(a) + lcs(a);
      if (cur < ans) {
        ans = cur;
        tmp = a;
      }
      // printf("lala %d\n", n);
    } while (next_permutation(a.begin(), a.end()));
    printf("%d %d: ", ans, n); for (int i = 0; i < n; i++) printf("%d ", tmp[i] + 1); printf("\n");
  }

  return 0;
}
