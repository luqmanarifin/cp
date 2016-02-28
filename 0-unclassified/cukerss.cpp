#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  
  int t;
  cin >> t;
  while(t--) {
    long long n, p;
    cin >> n >> p;
    for(int i = 0; i < p; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for(int mask = 1; mask < (1 << p); mask++) {
      long long now = 1;
      for(int i = 0; i < p; i++) {
        if(mask & (1 << i)) {
          now *= a[i];
          if(now > n || now < 0) break;
        }
      }
      if(now > n || now < 0) continue;
      long long add = n / now;
      int cnt = __builtin_popcount(mask);
      ans += (cnt % 2? add : -add) * (1LL << (cnt - 1));
    }
    cout << ans << endl;
  }
  
  return 0;
}
