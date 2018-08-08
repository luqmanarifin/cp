#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  int block = 0, ans = 1e9;
  for (int i = 1; i <= n; i++) {
    int cur = i + (n % i? n / i + 1 : n / i);
    if (cur < ans) {
      ans = cur;
      block = i;
    }
  }
  for (int i = 0; i < n; i++) a[i] = i;
  for (int i = 0; i < block; i++) cnt[i] = n / block;
  int rem = n % block;
  for (int i = 0; i < rem; i++) cnt[i]++;
  int st = 0;
  for (int i = 0; i < block; i++) {
    reverse(a + st, a + st + cnt[i]);
    st += cnt[i];
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i] + 1); printf("\n");

  return 0;
}
