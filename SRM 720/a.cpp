#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N], ten[N];
long long dp[15][N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

class SumProduct {
public:
  void pre() {
    fact[0] = ifact[0] = ten[0] = 1;
    for (int i = 1; i < N; i++) {
      fact[i] = fact[i - 1] * i % mod;
      ifact[i] = inv(fact[i]);
      ten[i] = ten[i - 1] * 10 % mod;
    }
  }

  long long perm(long long n, long long k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fact[n] * ifact[n - k] % mod;
  }
  
  long long comb(long long n, long long k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
  }
  
  int findSum(vector<int> c, int a, int b) {
    pre();
    long long ans = 0;
    int sum = 0;
    for (auto it : c) sum += it;
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < a; i++) s1 += ten[i];
    for (int i = 0; i < b; i++) s2 += ten[i];
    s1 %= mod;
    s2 %= mod;
    
    for (int p = 0; p < 10; p++) {
      for (int q = 0; q < 10; q++) {
        if (p == q && c[p] < 2) continue;
        if (p != q && (c[p] < 1 || c[q] < 1)) continue;
        c[p]--;
        c[q]--;
        
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < 10; i++) {
          for (int j = 0; j <= a + b - 2; j++) {
            for (int t = 0; j + t <= a + b - 2 && t <= c[i]; t++) {
              dp[i + 1][j + t] += dp[i][j] * comb(a + b - 2 - j, t);
              dp[i + 1][j + t] %= mod;
            }
          }
        }
        long long add = (p * s1 % mod) * (q * s2 % mod) % mod;
        long long cnt = dp[10][a + b - 2];
        add = add * cnt % mod;
        
        //if (add) printf("%d %d: %lld, %lld\n", p, q, add, cnt);
        ans += add;
        ans %= mod;
        
        c[p]++;
        c[q]++;
      }
    }  
    return (int) ans;
  }
};

/*
int main() {
  
  int l = 0;
  int r = 0;
  
  SumProduct kelas;
  cout << kelas.findSum({1,6,0,0,0,0,0,0,0,0}, 1, 2) << endl;
  
  return 0;
}
*/