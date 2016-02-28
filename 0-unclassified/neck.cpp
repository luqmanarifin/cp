#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long mod = 1e9 + 9; //15616516515631LL;
const long long prime = 31;

char s[N];
long long pre[N];
long long power[N];
bool done[N];
int ans[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s + 1);
  if(k == 1) {
    for(int i = 1; i <= n; i++) {
      printf("1");
    }
    return 0;
  }
  power[0] = 1;
  for(int i = 1; i <= n; i++) {
    power[i] = (power[i - 1] * prime) % mod;
    pre[i] = (pre[i - 1] * prime + s[i] - 'a' + 1) % mod;
  }
  for(int lom = n; lom >= 1; lom--) {
    for(int i = 2 * lom; i <= k * lom && i <= n; i += lom) {
      long long cur = pre[i] - pre[i - lom] * power[lom];
      cur %= mod; if(cur < 0) cur += mod;
      if(cur == pre[lom]) {
        if(i != 1LL * k * lom) continue;
        if(done[i]) continue;
        done[i] = 1;
        ans[i]++;
        int l = 0, r = min(lom, n - i);
        while(l < r) {
          int mid = (l + r + 1) >> 1;
          long long c = pre[i + mid] - pre[i] * power[mid];
          c %= mod; if(c < 0) c += mod;
          if(c == pre[mid]) l = mid;
          else r = mid - 1;
        }
        //printf("%d %d %d\n", i, lom, l);
        ans[i + l + 1]--;
      } else {
        break;
      }
    }
  }
  int now = 0;
  for(int i = 1; i <= n; i++) {
    now += ans[i];
    putchar(now > 0? '1' : '0');
  }
  printf("\n");
  return 0;
}
