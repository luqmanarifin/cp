#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long l[N], r[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", l + i);
    for (int i = 0; i < n; i++) scanf("%lld", r + i);
    for (int i = 0; i < n; i++) scanf("%lld", c + i);
    sort(l, l + n);
    sort(c, c + n);
    reverse(c, c + n);
    vector<long long> p;
    
    set<long long> s;
    for (int i = 0; i < n; i++) s.insert(r[i]);
    for (int i = n - 1; i >= 0; i--) {
      auto it = s.lower_bound(l[i]);
      p.push_back(*it - l[i]);
      s.erase(it);
    }

    sort(p.begin(), p.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += p[i] * c[i];
    printf("%lld\n", ans);
  }

  return 0;
}
