#include <bits/stdc++.h>

using namespace std;

vector<long long> all;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    long long n;
    scanf("%lld", &n);
    while (n) {
      all.push_back(n);
      n /= 2;
    }
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  while (m--) {
    int v;
    scanf("%d", &v);
    printf("%lld\n", all[v-1]);
  }

  return 0;
}
