#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    a[i]--;
  }
  long long tot = a[0];
  long long p = 0;
  long long val = 0;
  long long ans = tot;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] < a[i]) {
      p = a[i - 1];
      val = tot;
    } else {
      if(p < a[i]) {
        val = (val * p + a[i] - p) % mod;
        p = a[i];
      } else {
        val = (val * a[i]) % mod;
        p = a[i];
      }
    }
    val = (val + 1) % mod;
    //printf("%I64d %I64d\n", p, val);
    if(val < 0) val += mod;
    if(p < 0) p += mod;
    tot = (p * val + a[i] - p) % mod;
    if(tot < 0) tot += mod;
    ans = (ans + tot) % mod;
  }
  cout << ans << endl;
  return 0;
}
