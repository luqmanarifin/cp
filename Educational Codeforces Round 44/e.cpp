#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long a[N];
int bit[N];

void add(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

void add_range(int l, int r) {
  add(l, +1);
  add(r + 1, -1);
}

int main() {
  int n, k; long long d;
  scanf("%d %d %lld", &n, &k, &d);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  sort(a + 1, a + 1 + n);

  add_range(0, 0);

  for (int i = 1; i <= n; i++) {
    int ada = find(i - 1);
    if (ada) {
      int p = upper_bound(a + 1, a + 1 + n, a[i] + d) - a;
      if (p - i >= k) {
        add_range(i + k - 1, p - 1);
      }
    }
  }
  puts(find(n)? "YES" : "NO");

  return 0;
}
