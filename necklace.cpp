#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 9;//15616516515631LL;
const long long prime = 31;
const int N = 1e6 + 5;

int kel[N];
char s[N];
long long pre[N];
long long dem[N];
int ans[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  clock_t tt = clock();
  long long now = 1, bef = 0;
  for(int i = 0; i < n; i++) {
    if(i) {
      now *= prime;
      now %= mod;
    }
    bef += now * (s[i] - 'a' + 1);
    bef %= mod;
    pre[i] = bef;
    dem[i] = inv(now);
  }
  for(int lom = n; lom >= 1; lom--) {
    long long must = pre[lom - 1];
    long long seq = 1LL * lom * k;
    if(seq == lom) kel[lom - 1] = max(kel[lom - 1], lom);
    for(int i = 2 * lom - 1; i < n; i += lom) {
      long long cur = pre[i] - pre[i - lom];
      if(cur < 0) cur += mod;
      cur *= dem[i - lom + 1];
      cur %= mod;
      //cout << "i " << i << " lom " << lom << " cur " << cur << " must " << must << endl;
      if(cur == must) {
        if(seq == i + 1) kel[i] = max(kel[i], lom);
      } else {
        break;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    int it = kel[i];
    if(it * k == i + 1) {
      ans[i]++;
      int l = 0, r = it;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        long long cur = (pre[mid + i] - pre[i]) * dem[i + 1];
        cur %= mod; if(cur < 0) cur += mod;
        if(cur == pre[mid - 1]) l = mid;
        else r = mid - 1;
      }
      //printf("%d %d %d\n", i, l, it);
      ans[i + l + 1]--;
    }
  }
  long long ok = 0;
  for(int i = 0; i < n; i++) {
    ok += ans[i];
    putchar(ok > 0? '1' : '0');
  }
  printf("\n");
  tt = clock() - tt;
  printf ("It took me %lf ms\n", ((double)tt * 1000.0)/CLOCKS_PER_SEC);
  return 0;
}
