#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int BIG = 1e6 + 5;
const long long mod = 1e9 + 7;

long long two[N];
int a[N];
long long cnt[BIG];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 1; i < BIG; i++) {
    for (int j = i + i; j < BIG; j += i) {
      cnt[i] += cnt[j];
    }
  }
  two[0] = 1;
  for (int i = 1; i < N; i++) {
    two[i] = two[i - 1] * 2 % mod;
  }
  long long ans = 0;
  for (int i = BIG - 1; i > 1; i--) {
    if (cnt[i]) {
      //printf("%d: %d\n", i, cnt[i]);
      long long ways = 1LL * cnt[i] * two[cnt[i] - 1] % mod;
      for (int j = i + i; j < BIG; j += i) {
        ways -= cnt[j];
      }
      ways %= mod;
      if (ways < 0) ways += mod;
      ans += 1LL * ways * i;
      ans %= mod;
      
      cnt[i] = ways;
    }
  }
  cout << ans << endl;
  return 0;
}
