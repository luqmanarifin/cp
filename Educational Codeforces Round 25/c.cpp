#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);

  int ans = 0;
  long long now = k;
  for (int i = 0; i < n; i++) {
    int lim = (a[i] + 1) / 2;
    while (now < lim) {
      now = now * 2;
      ans++;
    }
    now = max(now, (long long) a[i]);
  }
  cout << ans << endl;
  return 0;
}
