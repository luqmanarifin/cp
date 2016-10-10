#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const int PRIME = 1307;
const int mod = 2e9 + 2153;

char a[N], b[N];
long long ha[N], hb[N];
long long power[N];

long long getA(int l, int r) {
  int cnt = r - l + 1;
  long long ret = ha[r] - ha[l - 1] * power[cnt] % mod;
  ret %= mod;
  if (ret < 0) ret += mod;
  return ret;
}

long long getB(int l, int r) {
  int cnt = r - l + 1;
  long long ret = hb[r] - hb[l - 1] * power[cnt] % mod;
  ret %= mod;
  if (ret < 0) ret += mod;
  return ret;
}

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME % mod;
  }
  
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s %s", b + 1, a + 1);
    int na = strlen(a + 1);
    int nb = strlen(b + 1);
    for (int i = 1; i <= na; i++) {
      ha[i] = (ha[i - 1] * PRIME + a[i] - 'A' + 1) % mod;
    }
    for (int i = 1; i <= nb; i++) {
      hb[i] = (hb[i - 1] * PRIME + b[i] - 'A' + 1) % mod;
    }
    bool ok = 0;
    int i = 1;
    long long allB = getB(1, nb);
    while (i + nb - 1 <= na) {
      printf("now %d\n", i);
      if (getA(i, i + nb - 1) == allB) {
        ok = 1;
        break;
      }
      int l = 1, r = nb;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (getA(i, i + mid - 1) != getB(1, mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      i += l;
    }
    printf("Case #%d: ", tt);
    puts(ok? "YES" : "NO");
  }
  
  return 0;
}