#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;

int cnt[N];
vector<long long> all;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    long long n;
    scanf("%lld", &n);
    while (n) {
      if (n < N) {
        cnt[n]++;
      } else {
        all.push_back(n);
      }
      n /= 2;
    }
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  int p = N, now = all.size();
  while (m--) {
    int v;
    scanf("%d", &v);
    if (v <= all.size()) {
      printf("%lld\n", all[v-1]);
    } else {
      while (now < v) {
        p--;
        now += cnt[p];
      }
      printf("%d\n", p);
    }
  }

  return 0;
}
