#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long prime = 971;
const long long mod = 2e9 + 89;

char s[N];
long long h[N];
long long power[N];

long long get(int l, int r) {
  int len = r - l + 1;
  long long ret = (h[r] - power[len] * h[l - 1] % mod) % mod;
  if(ret < 0) ret += mod;
  return ret;
}

int main() {
  int t;
  scanf("%d %s", &t, s + 1);
  int n = strlen(s + 1);
  power[0] = 1;
  for(int i = 1; i < N; i++) {
    power[i] = power[i - 1] * prime % mod;
  }
  
  if(t == 1) {
    if(n == 1 && s[1] == '-') {
      puts("WA");
      return 0;
    }
    if(n == 2 && s[1] == '-' && s[2] == '0') {
      puts("WA");
      return 0;
    }
    for(int i = (s[1] == '-'? 2 : 1); i <= n; i++) {
      if(!('0' <= s[i] && s[i] <= '9')) {
        puts("WA");
        return 0;
      }
    }
    if(n > 12) {
      puts("WA");
      return 0;
    }
    long long ret = 0;
    for(int i = (s[1] == '-'? 2 : 1); i <= n; i++) {
      ret = ret * 10 + s[i] - '0';
    }
    if(s[1] == '-') ret = -ret;
    if(-2147483648LL <= ret && ret <= 2147483646LL) {
      puts("AC");
    } else {
      puts("WA");
    }
  } else {
    if(n % 2 == 1) {
      puts("WA");
      return 0;
    }
    for(int i = 1; i <= n; i++) {
      h[i] = (h[i - 1] * prime + s[i]) % mod;
    }
    int m = n / 2;
    for(int len = 1; len < m; len++) {
      if(get(1, m - len) == get(m + len + 1, n) && get(m - len + 1, m) == get(m + 1, m + len)) {
        puts("AC");
        return 0;
      }
    }
    puts("WA");
  }
  
  return 0;
}
