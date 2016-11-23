#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int cnt[N], sum[N];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (i != s) {
      cnt[a[i]]++;
    }
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + cnt[i];
  }
  int ans = 1e9;
  int miss = 0;
  for (int i = 1; i < n; i++) {
    if (cnt[i] == 0) miss++;
    ans = min(ans, (a[s] != 0) + max(miss, cnt[0] + sum[i + 1]));
  }
  cout << ans << endl;
  return 0;
}
