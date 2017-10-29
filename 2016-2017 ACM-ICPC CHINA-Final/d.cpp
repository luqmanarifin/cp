#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long a[N];
int n, k;

bool can(int el) {
  multiset<long long> s;
  for (int i = 0; i < n; i++) s.insert(a[i]);
  vector<long long> acu;
  for (int cok = 0; cok < el; cok++) {
    auto it = s.end();
    it--;
    acu.push_back(*it);
    s.erase(it);
  }
  for (auto st : acu) {
    long long now = st;
    for (int i = 1; i < k; i++) {
      auto it = s.upper_bound(now / 2);
      if (it == s.begin()) return 0;
      it--;
      now = *it;
      s.erase(it);
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    int l = 0, r = n / k;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (can(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    printf("Case #%d: %d\n", tt, l);
  }

  return 0;
}
