
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];
int num[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", num + i);
  int s, f;
  scanf("%d %d", &s, &f);
  s--; f--;
  for (int i = 0; i < n; i++) {
    if (s < f) {
      a[s] += num[i];
      a[f] -= num[i];
      a[s + n] += num[i];
      a[f + n] -= num[i];
    } else {
      a[s] += num[i];
      a[f + n] -= num[i];
      a[0] += num[i];
      a[f] -= num[i];
      a[s + n] += num[i];
    }
    s = (s - 1 + n) % n;
    f = (f - 1 + n) % n;
  }
  for (int i = 1; i < 2 * n; i++) a[i] += a[i - 1];
  long long ans = -1, p = -1;
  for (int i = 0; i < 2 * n; i++) {
    if (a[i] > ans) {
      ans = a[i];
      p = i % n;
    }
  }
  printf("%lld\n", p + 1);
  return 0;
}
