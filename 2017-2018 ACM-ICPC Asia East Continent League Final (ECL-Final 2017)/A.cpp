#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long LL;

const int K = 1e5;
LL fact[K + 5];
LL invfact[K + 5];

LL sqr(LL a){
  return a * a % MOD;
}

LL modpow(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
  LL tmp = sqr(modpow(a, b >> 1));
  if(b & 1) tmp = tmp * a % MOD;
  return tmp;
}

LL inv(int a){
  return modpow(a, MOD - 2);
}

int main(){
  
  fact[0] = fact[1] = 1;
  for(int i = 2;i <= K; ++i) fact[i] = fact[i - 1] * i % MOD;
  invfact[0] = invfact[1] = 1;
  invfact[K] = inv(fact[K]);
  for(int i = K - 1;i >= 2; --i) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
  int t;
  scanf("%d", &t);
  
  for(int tc = 1; tc <= t; ++tc){
    LL ans = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    if(k <= n){
      LL kali = 1;
      for(int i = 0;i < k; ++i){
        ans += kali * invfact[i];
        ans %= MOD;
        kali = kali * (n - i) % MOD;
      } 
      
      ans = modpow(2, n) - ans;
      while(ans < 0) ans += MOD;
    }
    
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}
