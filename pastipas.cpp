#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int prime[] = {31, 71};
const long long mod[] = {(long long)1e9 + 7, (long long)2e9 + 89};

long long h[N][2];
long long power[N][2];
char s[N];

int same(int i, int j, int len) {
  assert(i <= j);
  for(int k = 0; k < 2; k++) {
    long long u = (h[i + len - 1][k] - h[i - 1][k] * power[len][k]) % mod[k];
    long long v = (h[j + len - 1][k] - h[j - 1][k] * power[len][k]) % mod[k];
    //u = u * power[j - i][k] % mod[k];
    if(u < 0) u += mod[k];
    if(v < 0) v += mod[k];
    //cout << "ASU " << h[i + len - 1][k] << endl;
    //cout << u << ' ' << v << endl;
    if(u != v) return 0;
  }
  return 1;
}

int main() {
  for(int j = 0; j < 2; j++) {
    power[0][j] = 1;
    for(int i = 1; i < N; i++) {
      power[i][j] = power[i - 1][j] * prime[j] % mod[j];
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 2; j++) {
        h[i][j] = (h[i - 1][j] * prime[j] + s[i] - 'A' + 1) % mod[j];
      }
      //cout << h[i][0] << ' ';
    }
    //cout << endl;
    ///cout << same(1, 6, 3) << endl;
    
    int i = 1, j = n;
    int ans = 0;
    
    while(i <= j) {
      int len = 1;
      while(!same(i, j - len + 1, len) && i + len - 1 < j - len + 1) len++;
      if(i + len - 1 < j - len + 1) {
        ans += 2;
      } else {
        ans++;
      }
      i += len;
      j -= len;
    }
    
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
