#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], cnt[N], s[N];
char junk[1005];

int main() {
  scanf("%s", junk);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = N - 2; i >= 0; i--) {
    s[i] = cnt[i] + s[i + 1];
  }
  long long ans = 0, now = 0;
  for (int i = 1; i + 1 < N; i++) {
    now += cnt[i-1];
    ans += 1LL * now * cnt[i] * s[i + 1];
  }
  cout << ans << endl;
  return 0;
}
