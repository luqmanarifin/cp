#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 998244353;

long long a[N];

long long cnt[N];
bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    long long ans = 0;
    vector<pair<long long, long long>> s = {{a[n - 1], 1}};  // value - cnt
    for (int i = n - 2; i >= 0; i--) {
      vector<pair<long long, long long>> new_bar = {{a[i], 1}};
      for (auto it : s) {
        long long bar = it.first;
        long long need = (a[i] + bar - 1) / bar;
        ans += it.second * (need - 1) % mod * (i + 1);
        ans %= mod;
        new_bar.emplace_back(a[i] / need, it.second);
      }
      for (auto it : new_bar) {
        cnt[it.first] += it.second;
      }
      s.clear();
      for (auto it : new_bar) {
        if (done[it.first]) continue;
        done[it.first] = 1;
        s.emplace_back(it.first, cnt[it.first]);
      }
      for (auto it : new_bar) {
        cnt[it.first] = 0;
        done[it.first] = 0;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
