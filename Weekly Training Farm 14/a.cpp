#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], s[N];

long long find(int l, int r) {
  return s[r] - s[l - 1];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i < n; i++) {
    long long lef = find(1, i + 1);
    long long rig = find(n - i + 1, n);
    if (lef <= rig) {
      puts("bad");
      printf("%d\n", i);
      return 0;
    }
  }
  puts("good");
  return 0;
}
