#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int pol = 1e6 + 5;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long ambil(int n, int k) {
  return fact[n] * ifact[n - k] % mod;
}

char s[pol];
int a[N];

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  int t;
  scanf("%d\n", &t);
  while(t--) {
    int n, num; char junk;
    {
      gets(s);
      stringstream ss(s);
      ss >> junk >> junk >> n;
    }
    {
      gets(s);
      stringstream ss(s);
      for(int i = 0; i < 4; i++) {
        ss >> junk;
      }
      int size = 1; a[0] = 1;
      while(ss >> num) {
        a[size++] = num;
      }
      long long ans = 1;
      int now = n + 1;
      int all = n;
      for(int i = size - 1; i >= 0; i--) {
        ans = ans * ambil(all - 1, now - a[i] - 1) % mod;
        all -= now - a[i];
        now = a[i];
      }
      printf("%d\n", (int) ans);
    }
    gets(s);
  }
  
  return 0;
}
