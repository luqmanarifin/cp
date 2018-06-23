#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
  int need = (n % 2? 9 * n / 2 + 1 : 9 * n / 2);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n && sum < need; i++) {
    ans++;
    sum += 5 - a[i];
  }
  cout << ans << endl;
  return 0;
}
