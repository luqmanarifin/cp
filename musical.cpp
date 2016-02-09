#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];
long long tmp[N], m;
int n;

long long solve(long long z) {
  long long ans = a[z % (2*n + 2)] % m;
  if(ans < 0) ans += m;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(a, 0, sizeof(a));
    long long z;
    scanf("%d %lld %lld", &n, &m, &z);
    for(int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      tmp[i] = a[i];
    }
    if(n == 1) {
      cout << a[0] << endl;
      continue;
    }
    a[n] = 0;
    a[2*n+1] = 0;
    for(int i = 0; i < n; i++) {
      if(n % 2 == 0) {
        a[n] += (i % 2 == 0? a[n - i - 1] : -a[n - i - 1]);
        a[2*n+1] += (i % 2? a[n - i - 1] : -a[n - i - 1]);
        a[n+1+i] = -a[i];
      } else {
        a[n] += (i % 2 == 0? a[n - i - 1] : -a[n - i - 1]);
        a[2*n+1] += (i % 2 == 0? a[n - i - 1] : -a[n - i - 1]);
        a[n+1+i] = a[i];
      }
      a[n] %= m;
      a[2*n+1] %= m;
    }
    cout << solve(z) << endl;
  }
  
  return 0;
}
