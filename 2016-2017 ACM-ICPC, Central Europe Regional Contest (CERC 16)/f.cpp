#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
bool ca[N], cb[N];
int ok[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  for (int i = 1; i <= n; ++i)
    scanf("%d", b+i);
  for (int i = 1; i <= n; ++i)
    ca[a[i]] = 1, cb[b[i]] = 1;
  int ans = 0;
  int same = 0;
  for (int i = 1; i <= n; ++i) {
    if (!ca[i] && !cb[i]) {
      int now = i;
      while (a[now] == b[now] && now > 0) {
        ok[now] = 1;
        now = a[now];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (ok[i]) continue;
    ans += a[i] > 0;
    ans += b[i] > 0;
  }
  printf("%d\n", ans);
  
  return 0;
}
