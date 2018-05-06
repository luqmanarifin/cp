
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], all[N], s[N];
int ok[N];

int find(int l, int r) {
  if (l > r) return 0;
  return s[r] - s[l-1];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    all[i] = all[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", ok + i);
    s[i] = s[i - 1];
    if (ok[i]) {
      s[i] += a[i];
    }
  }
  long long ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    long long cur = find(1, i - 1) + find(i + k, n) + all[i + k - 1] - all[i - 1];
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
