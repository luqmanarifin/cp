#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;

set<pair<long long, int>> s;
int a[N];
int n, k, l, m;

pair<long long, int> get_k() {
  auto it = s.end();
  for (int i = 0; i < k; i++) it--;
  return *it;
}

void remove(int kali) {
  while (kali--) {
    auto it = s.end();
    it--;
    // printf("hapus %lld\n", it->first);
    s.erase(it);
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &l);
  int mini = inf;
  m = n * k;
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
    s.insert(make_pair(a[i], i));
    mini = min(mini, a[i]);
  }
  long long lim = (long long) mini + l;
  long long ans = 0;
  for (int iter = 0; iter < n; iter++) {
    auto it = s.lower_bound(make_pair(lim, inf));
    if (it == s.begin()) {
      puts("0");
      return 0;
    }
    it--;
    auto k_biggest = get_k();

    auto cur = min(*it, k_biggest);
    ans += cur.first;
    s.erase(cur);
    // printf("hapusss %lld\n", cur.first);
    remove(k - 1);
  }
  cout << ans << endl;
  return 0;
}
