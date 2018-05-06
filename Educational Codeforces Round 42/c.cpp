
#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int a[N];

bool sq(int n) {
  int q = (int) sqrt(n);
  if (q * q == n) return 1;
  q++;
  if (q * q == n) return 0;
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int len = 0;
  for (int i = 0; n; i++) {
    len++;
    a[i] = n % 10;
    n /= 10;
  }
  int ans = N;
  for (int mask = 0; mask < (1 << len); mask++) {
    if (__builtin_popcount(mask) == len) continue;
    bool can = 1;
    for (int i = len - 1; i >= 0; i--) {
      if ((mask & (1 << i)) == 0) {
        if (a[i] == 0) {
          can = 0;
        }
        break;
      }
    }    
    if (!can) continue;
    int now = 0;
    for (int i = len - 1; i >= 0; i--) {
      if ((mask & (1 << i)) == 0) {
        now = now * 10 + a[i];
      }
    }
    if (sq(now)) {
      //cout << now << endl;
      ans = min(ans, __builtin_popcount(mask));
    }
  }
  if (ans == N) {
    puts("-1");
  } else {
    cout << ans << endl;
  }
  return 0;
}
