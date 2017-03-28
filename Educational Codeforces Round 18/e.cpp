#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N], n;
vector<int> seg[N];

vector<int> all, dp;

int get(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

void solve(int k) {
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long l = 1, r = 1e9;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if ((k + 1) * mid < a[i]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    ans += l;
  }
  cout << ans << endl;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        seg[i].push_back(a[i] / j);
        seg[i].push_back(a[i] / j - 1);
      } else {
        seg[i].push_back(a[i] / j);
      }
    }
    sort(seg[i].begin(), seg[i].end());
    seg[i].resize(distance(seg[i].begin(), unique(seg[i].begin(), seg[i].end())));
  }
  for (int i = 0; i < n; i++) {
    for (auto it : seg[i]) {
      all.push_back(it);
    }
  }
  all.push_back(0);
  all.push_back(2e9);
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  dp.resize(all.size() + 1);
  for (int i = 0; i < n; i++) {
    auto beg = seg[i].begin();
    dp[get(0)]++;
    dp[get(*beg) + 1]--;
    for (auto it : seg[i]) {
      if (it == *beg) continue;
      int id = get(it);
      //printf("%d dari %d\n", it, id);
      dp[id]++;
      dp[id + 1]--;
    }
  }
  for (int i = 1; i < dp.size(); i++) dp[i] += dp[i - 1];
  //for (auto it : all) printf("%d ", it); printf("\n");
  //for (int i = 0; i < dp.size(); i++) printf("%d ", dp[i]); printf("\n");
  for (int i = dp.size() - 1; i >= 0; i--) {
    if (dp[i] == n) {
      solve(all[i]);
      return 0;
    }
  }
  return 0;
}
