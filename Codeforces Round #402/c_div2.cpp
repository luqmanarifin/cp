#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

tuple<int, int, int> a[N];
int p[N], q[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) scanf("%d", q + i);
  for (int i = 0; i < n; i++) {
    a[i] = make_tuple(p[i] - q[i], p[i], q[i]);
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int dif, av, bv;
    tie(dif, av, bv) = a[i];
    ans += av;
  }
  for (int i = k; i < n; i++) {
    int dif, av, bv;
    tie(dif, av, bv) = a[i];
    if (av < bv) {
      ans += av;
    } else {
      ans += bv;
    }
  }
  cout << ans << endl;
  return 0;
}
