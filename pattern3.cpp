#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long mod[] = {(long long)1e9 + 7, (long long)2e9 + 89};
const long long prime[] = {31, 71};

char s[N];
long long h[N][2];
long long power[N][2];

int main() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      power[i][j] = (power[i - 1][j] * prime[j]) % mod[j];
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 2; j++) {
        h[i][j] = (h[i - 1][j] * prime[j] + s[i] - 'a' + 1) % mod[j];
      }
    }
    /*
    for(int i = 1; i <= n; i++) {
      cout << h[i][0] << ' ';
    }
    cout << endl;
    */
    for(int i = 1; i <= n; i++) {
      bool nice = 1;
      int last = -1;
      int rem;
      long long v, cur;
      for(int at = i; at <= n; at += i) {
        last = at;
        for(int j = 0; j < 2; j++) {
          cur = (h[at][j] - h[at - i][j] * power[i][j]) % mod[j];
          if(cur < 0) cur += mod[j];
          //if(i == 2) cout << "awal " << v << ' ' << cur << endl;
          if(h[i][j] != cur) {
            nice = 0;
            goto NEXT;
          }
        }
      }
      rem = n - last;
      
      if(rem) {
        for(int j = 0; j < 2; j++) {
          cur = (h[n][j] - h[n - rem][j] * power[rem][j]) % mod[j];
          if(cur < 0) cur += mod[j];
          //if(i == 2) cout << v << ' ' << cur << endl;
          if(h[rem][j] != cur) {
            nice = 0;
            goto NEXT;
          }
        }
      }
      NEXT:;
      if(nice == 0) {
        continue;
      }
      
      printf("%d\n", i);
      break;
    }
  }
  
  return 0;
}
