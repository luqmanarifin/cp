#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

long long a[N], s[N];
int to[N];
int add[N];

int main() {
  int r, k, n;
  scanf("%d %d %d", &r, &k, &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  for (int i = 0; i < n; i++) a[n + i] = a[i];
  for (int i = 0; i < 2 * n; i++) s[i] = (i? s[i - 1] : 0) + a[i];
  for (int i = 0; i < n; i++) {
    long long now = a[i];
    int j = i;
    //printf("lala %I64d %d\n", now + a[j + 1], k);
    while (now + a[j + 1] <= k && j + 1 < i + n) {
      now += a[++j];
    }
    //printf("%d %d\n", i, j);
    to[i] = j % n;
    add[i] = s[j] - (i? s[i - 1] : 0);
    //printf("%d muat %d\n", i, add[i]);
  }
  int now = 0;
  long long ans = 0;
  for (int i = 0; i < r; i++) {
    ans += add[now];
    now = (to[i] + 1) % n;
  }
  cout << ans << endl;
  return 0;
}
