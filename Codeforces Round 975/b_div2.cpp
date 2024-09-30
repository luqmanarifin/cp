#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
map<long long, long long> ans;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ans.clear();

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    ans[n - 1]++;
    for (long long i = 1; i < n; i++) {
      long long here = i * (n - i - 1) + n - 1;
      ans[here]++;
      if (a[i] - 1 > a[i - 1]) {
        long long bef = i * (n - i);
        ans[bef] += a[i] - a[i - 1] - 1;
      }
    }
    for (int i = 0; i < q; i++) {
      long long v;
      scanf("%lld", &v);
      printf("%lld%c", ans[v], i + 1 == q? '\n' : ' ');
    }
  }

  return 0;
}
