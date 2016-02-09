#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

#define int long long

int a[N], b[N];
int ada[N];
int p[N];

int power(int u, int v) {
  if(v == 0) return 1;
  int t = power(u, v / 2);
  t *= t;
  if(v & 1) {
    t *= u;
  }
  return t;
}

int get(long long num, int at) {
  for(int i = 0; i < at; i++) {
    num /= 10;
  }
  return num % 10;
}

main() {
  for(int i = 0; i < 12; i++) {
    p[i] = power(10, i);
  }
  
  int n, k;
  scanf("%I64d %I64d", &n, &k);
  for(int i = 0; i < n / k; i++) {
    scanf("%I64d", a + i);
  }
  for(int i = 0; i < n / k; i++) {
    scanf("%I64d", b + i);
  }
  for(int i = 0; i < n / k; i++) {
    long long l = 0, r = (p[k] - 1) / a[i] + 1;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(get(mid * a[i], k - 1) < b[i]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    long long low = l;
    
    l = 0, r = (p[k] - 1) / a[i] + 1;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(get(mid * a[i], k - 1) <= b[i]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    long long hig = l;
    
    long long cnt = max(0LL, hig - low);
    //printf("cnt %I64d %I64d\n", i, cnt);
    ada[i] = (p[k] - 1) / a[i] + 1 - cnt;
  }
  long long ans = 1;
  for(int i = 0; i < n / k; i++) {
    ans = ans * ada[i] % mod;
  }
  cout << ans << endl;
  return 0;
}
