#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int f[N];

int main() {
  int n, k, a;
  scanf("%d %d %d", &n, &k, &a);
  f[a] = 1;
  for(int i = 2*a + 1; i < N; i += a + 1) {
    f[i] = f[i - a - 1] + 1;
  }
  for(int i = 1; i < N; i++) {
    f[i] = max(f[i], f[i - 1]);
  }
  
  set<pair<int, int>> ava;
  ava.insert(make_pair(1, n));
  int now = f[n];
  assert(now >= k);
  
  int q;
  scanf("%d", &q);
  for(int i = 1; i <= q; i++) {
    int dor;
    scanf("%d", &dor);
    auto it = ava.upper_bound(make_pair(dor, N));
    it--;
    now -= f[it->second - it->first + 1];
    if(it->first != dor) {
      now += f[dor - it->first];
      ava.insert(make_pair(it->first, dor - 1));
    }
    if(it->second != dor) {
      now += f[it->second - dor];
      ava.insert(make_pair(dor + 1, it->second));
    }
    ava.erase(it);
    if(now < k) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
