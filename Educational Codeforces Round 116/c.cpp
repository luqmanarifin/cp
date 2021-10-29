#include <bits/stdc++.h>

using namespace std;

const int N = 15;

long long ten[N];

int a[N];
long long max_cnt[N];

long long get_ans(int n, long long k) {
  long long ans = 0;
  for (int j = 0; j + 1 < n; j++) {
    long long cur = min(max_cnt[j], k);
    ans += cur * ten[a[j]];
    k -= cur;
  }
  ans += k * ten[a[n - 1]];
  return ans;
}

int main() {
  ten[0] = 1;
  for (int i = 1; i < N; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (i > 0) {
        max_cnt[i - 1] = ten[a[i] - a[i - 1]] - 1;
      }
    }
    printf("%lld\n", get_ans(n, k + 1));
  }
  
  return 0;
}
