
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long save[N], ori[N], s[N];
int a[N];
int n, R;
long long k;

bool can(long long x) {
  long long need = 0, add = 0;
  for (int i = 1; i <= n; i++) s[i] = ori[i], save[i] = 0;
  for (int i = 1; i <= n; i++) {
    add += save[i];
    long long now = s[i] + add;
    if (now < x) {
      int at = min(n, i + R);
      int l = max(1, at - R);
      int r = min(n, at + R);
      need += x - now;
      add += x - now;
      save[r + 1] += now - x;
    }
    if (need > k) return 0;
  }
  return 1;
}

int main() {
  scanf("%d %d %lld", &n, &R, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int l = max(1, i - R);
    int r = min(n, i + R);
    ori[l] += a[i];
    ori[r + 1] -= a[i];
  }
  for (int i = 1; i <= n; i++) ori[i] += ori[i-1];
  long long l = 0, r = 2e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
