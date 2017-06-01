#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
int n, s;

long long solve(int k) {
  vector<long long> h;
  for (int i = 1; i <= n; i++) {
    h.push_back(a[i] + 1LL * i * k);
  }
  sort(h.begin(), h.end());
  long long ret = 0;
  for (int i = 0; i < k; i++) {
    ret += h[i];
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (solve(mid) <= s) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d %I64d\n", l, solve(l));
  return 0;
}
