#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const long long mod = 1e9 + 7;

bool is[N];
vector<int> p, pk;
int n, lim;

// udah - mask udah - last
long long dp[20][1 << 15][20];
long long fact[N], ifact[N];

int get_lsb(int mask) {
  if(mask == 0) return -1;
  int ret = mask & (mask - 1);
  int t = abs(ret - mask);
  return (__builtin_clz(t) ^ 31);
}

int get_msb(int mask) {
  if(mask == 0) return -1;
  return (__builtin_clz(mask) ^ 31);
}

int power(int a, int b) {
  if(b == 0) return 1;
  int temp = power(a, b / 2);
  temp *= temp;
  if(b & 1) {
    temp *= a;
  }
  return temp;
}

long long powmod(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = powmod(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return powmod(a, mod - 2);
}

long long c(int all, int k) {
  if(all < k || all < 0 || k < 0) return 0;
  return fact[all] * ifact[k] % mod * ifact[all - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      if(i < 50) {
        p.push_back(i);
      } else {
        pk.push_back(i);
      }
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }

  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &n, &lim);
    
    // mask - ada berapa cara
    vector<pair<int, int>> a;
    for(int i = 0; i < p.size(); i++) {
      for(int j = i + 1; j < p.size(); j++) {
        for(int k = j + 1; k < p.size(); k++) {
          int cur = 1;
          int add = 0;
          for(int ci = 1; cur * power(p[i], ci) <= lim; ci++) {
            cur *= power(p[i], ci);
            for(int cj = 1; cur * power(p[j], cj) <= lim; cj++) {
              cur *= power(p[j], cj);
              for(int ck = 1; cur * power(p[k], ck) <= lim; ck++) {
                cur *= power(p[k], ck);
                add++;
                cur /= power(p[k], ck);
              }
              cur /= power(p[j], cj);
            }
            cur /= power(p[i], ci);
          }
          if(add) {
            a.emplace_back((1 << i) | (1 << j) | (1 << k), add);
          }
        }
      }
    }
    
    for(int i = 0; i < p.size(); i++) {
      for(int j = i + 1; j < p.size(); j++) {
        int cur = 1;
        int add = 0;
        for(int ci = 1; cur * power(p[i], ci) <= lim; ci++) {
          cur *= power(p[i], ci);
          for(int cj = 1; cur * power(p[j], cj) <= lim; cj++) {
            cur *= power(p[j], cj);
            add++;
            cur /= power(p[j], cj);
          }
          cur /= power(p[i], ci);
        }
        if(add) {
          a.emplace_back((1 << i) | (1 << j), add);
        }
      }
    }
    
    for(int i = 0; i < p.size(); i++) {
      int cur = 1;
      int add = 0;
      for(int ci = 1; cur * power(p[i], ci) <= lim; ci++) {
        cur *= power(p[i], ci);
        add++;
        cur /= power(p[i], ci);
      }
      if(add) {
        a.emplace_back((1 << i), add);
      }
    }
    
    dp[0][0][0] = 1;
    for(int i = 0; i <= min(n, (int) p.size()); i++) {
      for(int mask = 0; mask < (1 << p.size()); mask++) {
        for(int j = 0; j < p.size(); j++) {
          if(dp[i][mask][j] == 0) continue;
          for(int p = 0; p < a.size(); p++) {
            int cm = a[p].first;
            if(mask & cm) continue;
            int to = get_lsb(cm);
            if(j <= to) {
              long long cur = dp[i][mask][j] * (n - i) % mod;
              cur = cur * a[p].second % mod;
              dp[i + 1][mask | cm][to] += cur;
              dp[i + 1][mask | cm][to] %= mod;
            }
          }
        }
      }
    }
    
    int can = 0;
    long long ans = 0;
    for(auto it : pk) can += it <= lim;
    for(int i = 0; i <= min(n, (int) p.size()); i++) {
      int sisa = n - i;
      vector<long long> pake;
      pake.assign(min(sisa, can) + 1, 1);
      for(int j = 1; j <= min(sisa, can); j++) {
        pake[j] = pake[j - 1] * (sisa - j + 1) % mod;
      }
      for(int j = 1; j <= min(sisa, can); j++) {
        pake[j] = pake[j] * c(can, j) % mod;
      }
      //printf("%d: ", i); for(int j = 0; j < pake.size(); j++) printf("%lld ", pake[j]); printf("\n");
      for(int mask = 0; mask < (1 << p.size()); mask++) {
        for(int k = 0; k < p.size(); k++) {
          if(dp[i][mask][k] == 0) continue;
          for(int j = 0; j <= min(sisa, can); j++) {
            ans += dp[i][mask][k] * pake[j];
            ans %= mod;
          }
        }
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}