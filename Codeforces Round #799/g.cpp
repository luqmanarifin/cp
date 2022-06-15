#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> p = {0};
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (i > 1) {
        if (a[i-1] >= 2 * a[i]) {
          p.push_back(i-1);
        }
      }
    }
    p.push_back(n);
    int ans = 0;
    for (int i = 1; i < p.size(); i++) {
      int num = p[i] - p[i-1];
      if (num > k) {
        ans += num - k;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
