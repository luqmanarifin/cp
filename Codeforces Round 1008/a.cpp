#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) scanf("%lld", a + i);
    sort(a, a + 2 * n);
    long long sum = 0;
    vector<int> good, bad;
    for (int i = 0; i < 2 * n; i++) {
      if (i < n - 1) {
        bad.push_back(a[i]);
        sum -= a[i];
      } else {
        good.push_back(a[i]);
        sum += a[i];
      }
    }
    int pg = 0, pb = 0;
    for (int i = 0; i < 2 * n + 1; i++) {
      if (i == 1) {
        printf("%lld", sum);
      } else if (i % 2 == 0) {
        printf("%d", good[pg++]);
      } else {
        printf("%d", bad[pb++]);
      }
      printf("%c", i == 2 * n? '\n' : ' ');
    }
  }

  return 0;
}
