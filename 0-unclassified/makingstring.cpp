#include <bits/stdc++.h>

using namespace std;

long long a[26];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i++) {
    if(i && a[i - 1] <= a[i]) {
      a[i] = a[i - 1] - 1;
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) if(a[i] > 0) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
