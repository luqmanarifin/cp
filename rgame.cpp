#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

long long dua[N], a[N], s[N];

int main() {
  dua[0] = 1;
  for(int i = 1; i < N; i++) dua[i] = dua[i - 1] * 2 % mod;
  
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(s, 0, sizeof(s));
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
      scanf("%lld", a + i);
    }
    for(int i = n; i >= 0; i--) {
      s[i] = (s[i + 1] + a[i] * dua[n - i]) % mod;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      long long b = 2;
      if(i >= 3) {
        b = b * dua[i - 2] % mod;
      }
      long long add = a[i - 1] * s[i] % mod;
      add = add * b % mod;
      ans += add;
    }
    printf("%lld\n", ans % mod);
  }
  
  return 0;
}
