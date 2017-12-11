#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

long long s[N];
long long ans[N];

long long compute(int n) {
  int ret = 0;
  while (n) {
    int c = n % 10;
    ret += (c % 2? +c : -c);
    n /= 10;
  }
  return abs(ret);
}

long long take(int l, int r) {
  if (l > r) return 0;
  return s[r] - s[l - 1];
}

int main() {
  for (int i = 1; i < N; i++) {
    s[i] = s[i - 1] + compute(i);
  }
  for (int i = 1; i <= 1000000; i++) {
    ans[i] = ans[i - 1] + take(i + 1, i + i) + take(i + 1, i + i - 1);
    assert(ans[i] >= 0);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", ans[n]);
  }

  return 0;
}
