#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];
long long l[N];
long long r[N];

int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++) {
    l[i] = l[i - 1] | a[i];
  }
  for(int i = n; i >= 1; i--) {
    r[i] = r[i + 1] | a[i];
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    int ping = k;
    while(ping--) {
      a[i] *= x;
    }
    ans = max(ans, l[i - 1] | a[i] | r[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
