#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 3e4 + 5;
const long long prime[] = {31, 71};
const long long mod[] = {(long long)2e9 + 89, (long long) 1e9 + 9};

int dp[N];
char s[N];
long long power[N][2];

int main() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      power[i][j] = power[i - 1][j] * prime[j] % mod[j];
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    set<long long> done;
    
    int n, a, b;
    scanf("%d %d %d %s", &n, &a, &b, s + 1);
    for(int i = 1; i <= n; i++) {
      dp[i] = inf;
    }
    //puts("abis baca");
    for(int i = 1; i <= n; i++) {
      dp[i] = min(dp[i], dp[i - 1] + a);
      long long h[2] = {};
      for(int j = i; j >= 1; j--) {
        for(int k = 0; k < 2; k++) {
          h[k] = (h[k] + power[i - j][k] * (s[j] - 'a' + 1)) % mod[k];
        }
        long long cur = h[0] * mod[1] + h[1];
        done.insert(cur);
      }
      //printf("%d precompute done\n", i);
      long long v[2] = {};
      for(int j = i + 1; j <= n; j++) {
        for(int k = 0; k < 2; k++) {
          v[k] = (v[k] * prime[k] + (s[j] - 'a' + 1)) % mod[k];
        }
        long long cur = v[0] * mod[1] + v[1];
        if(done.count(cur)) {
          dp[j] = min(dp[j], dp[i] + b);
        } else {
          break;
        }
      }
    }
    printf("%d\n", dp[n]);
  }
  
  return 0;
}
