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
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    priority_queue<int> pq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      pq.push(a[i]);
      if ((n - i) % (k + 1) == 0) {
        ans += pq.top();
        pq.pop();
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
