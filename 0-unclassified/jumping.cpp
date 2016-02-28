#include <bits/stdc++.h>

using namespace std;

const int pol = 1e9;
const int N = 1e5;

vector<int> prime;
bool is[N];

int a[305];
int c[305];
vector<int> fact[305];
int mask[305];
int dp[1 << 9][305];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      prime.push_back(i);
      for(long long j = (long long) i*i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    int t = a[i];
    for(auto it : prime) {
      if(t == 1) break;
      if(t % it == 0) {
        fact[i].push_back(it);
      }
      while(t % it == 0) t /= it;
    }
    if(t != 1) {
      fact[i].push_back(t);
    }
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  
  int ans = pol;
  for(int i = 0; i < n; i++) {
    swap(a[0], a[i]);
    swap(c[0], c[i]);
    swap(fact[0], fact[i]);
    
    int m = fact[0].size();
    memset(mask, 0, sizeof(mask));
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        if(a[j] % fact[0][k] == 0) {
          mask[j] |= (1 << k);
        }
      }
    }
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < (1 << m); k++) {
        dp[j][k] = pol;
      }
    }
    dp[0][(1 << m) - 1] = c[0];
    for(int j = 1; j < n; j++) {
      for(int k = 0; k < (1 << m); k++) {
        dp[j][k] = dp[j - 1][k];
      }
      for(int k = 0; k < (1 << m); k++) {
        dp[j][k & mask[j]] = min(dp[j][k & mask[j]], dp[j - 1][k] + c[j]);
      }
    }
    for(int j = 0; j < n; j++) {
      ans = min(ans, dp[j][0]);
    }
    
    swap(a[0], a[i]);
    swap(c[0], c[i]);
    swap(fact[0], fact[i]);
  }
  cout << (ans == pol? -1 : ans) << endl;
  return 0;
}