#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<pair<int, int>> s;
multiset<long long> val;

int a[N], per[N];
long long sum[N];

long long find(int l, int r) {
  return sum[r] - sum[l - 1];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", per + i);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  s.insert({1, n});
  val.insert(sum[n]);
  for (int i = 1; i <= n; i++) {
    auto it = s.lower_bound({per[i], 1e9});
    assert(it != s.begin());
    it--;
    val.erase(val.find(find(it->first, it->second)));
    if (it->first < per[i]) {
      s.insert({it->first, per[i] - 1});
      val.insert(find(it->first, per[i] - 1));
    }
    if (per[i] < it->second) {
      s.insert({per[i] + 1, it->second});
      val.insert(find(per[i] + 1, it->second));
    }
    s.erase(*it);
    //for (auto it : s) printf("%d %d, ", it.first, it.second); printf("\n");
    auto ans = val.rbegin();
    if (val.empty()) {
      puts("0");
    } else {
      printf("%I64d\n", *ans);
    }
  }

  return 0;
}
