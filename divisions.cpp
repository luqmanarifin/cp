#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 3;

bitset<N> is;

int main() {
  long long n;
  scanf("%I64d", &n);
  
  long long ans = 1;
  int cur = 0;
  while(n % 2 == 0) {
    cur++;
    n /= 2;
  }
  ans *= cur + 1;
  for(long long i = 3; i * i <= n; i += 2) {
    if(!is[i]) {
      cur = 0;
      while(n % i == 0) {
        cur++;
        n /= i;
      }
      ans *= cur + 1;
      for(long long j = i * i; j * j <= n; j += i + i) {
        is[j] = 1;
      }
    }
  }
  if(n != 1) {
    ans *= 2;
  }
  cout << ans << endl;
  return 0;
}
