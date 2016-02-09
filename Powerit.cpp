#include <bits/stdc++.h>

using namespace std;

class Powerit {
public:
  int eulertot(int a) {
    int ret = 0;
    for(int i = 1; i * i <= a; i++) {
      if(a % i == 0) {
        ret++;
        if(i * i != a) {
          ret++;
        }
      }
    }
    ret--; // because of 1
    return a - ret;
  }
  long long power(long long a, long long k, long long mod) {
    long long now = a;
    for(int i = 1; i < k; i++) {
      now *= now;
      now %= mod;
      now *= a;
      now %= mod;
    }
    return now;
  }
  int calc(int n, int k, int mod) {
    dp.resize(n + 1);
    long long ans = 0;
    //int euler = eulertot(mod);
    for(int i = 1; i <= n; i++) {
      int v = i;
      long long add = 1;
      for(int j = 2; j * j <= v; j++) {
        if(v % j == 0) {
          add *= dp[j];
          add %= mod;
          v /= j;
        }
      }
      if(v != i) {
        add *= dp[v];
        add %= mod;
      } else {
        add *= power(v, k, mod);
      }
      dp[i] = add;
      ans += add;
      ans %= mod;
    }
    return (int) ans;
  }
  vector<long long> dp;
};
/*
int main() {
  
  Powerit kelas;
  cout << kelas.calc(1134, 35, 411442879) << endl;
  cout << kelas.power(2, 3, 10000) << endl;
  return 0;
}
*/