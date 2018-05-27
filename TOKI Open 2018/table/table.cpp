#include "table.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int CONST_N = 4005;
const long long mod = 1e9 + 7;
const long long REM = 100;

bool bad[CONST_N][CONST_N];
long long tmp[105];

long long cnt[105];   // kemunculan sesuatu
long long ways[105];

long long per[105];

long long fact[CONST_N * CONST_N], ifact[CONST_N * CONST_N];

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

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int countSubsets(int M, int N, int K, std::vector<int> C, std::vector<int> D) {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < CONST_N * CONST_N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  //for (int i = 0; i < 10; i++) printf("%lld ", fact[i]); printf("\n");
  //for (int i = 0; i < 10; i++) printf("%lld ", ifact[i]); printf("\n");
  //cout << c(10, 5) << endl;
  for (int i = 0; i < K; i++) {
    bad[C[i]][D[i]] = 1;
  }
  for (int i = 1; i <= M; i++) {
    long long now = 1;
    for (int j = 1; j <= N; j++) {
      now = now * i % REM;
      if (bad[i][j]) continue;
      cnt[now]++;
    }
  }
  //for (int i = 0; i < REM; i++) printf("%lld ", cnt[i]); printf("\n");
  memset(ways, 0, sizeof(ways));
  ways[0] = 1;
  for (int j = 0; j < REM; j++) {
    memset(per, 0, sizeof(per));
    //if (cnt[j]) printf("%d ada %d\n", j, cnt[j]);
    for (int k = 0; k <= cnt[j]; k++) {
      per[j * k % REM] += c(cnt[j], k);
      per[j * k % REM] %= mod;
      //printf("lol %lld\n", per[j * k % REM]);
    }
    //for (int i = 0; i < REM; i++) printf("%lld ", per[i]); printf("\n");
    memset(tmp, 0, sizeof(tmp));
    for (int k = 0; k < REM; k++) {
      for (int add = 0; add < REM; add++) {
        tmp[(k + add) % REM] += ways[k] * per[add];
        tmp[(k + add) % REM] %= mod;
      }
    }
    for (int k = 0; k < REM; k++) ways[k] = tmp[k];
    //for (int i = 0; i < REM; i++) printf("%lld ", ways[i]); printf("\n");
  }
  //for (int i = 0; i < REM; i++) printf("%lld ", ways[i]);
  return ways[13];
}
