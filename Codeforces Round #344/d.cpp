#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod[] = {(long long)2e9 + 89, (long long)1e9 + 7};
const long long prime[] = {28000163, 30000001};
 
long long h[N][2], power[N][2];
long long ta[N], ca[N], tb[N], cb[N];
long long va[N][2], vb[N][2];
int n, m;

void init() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      power[i][j] = power[i - 1][j] * prime[j] % mod[j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      va[i][j] = (ta[i] * 27 + ca[i]) % mod[j];
    }
  }
  for(int i = 1; i <= m; i++) {
    for(int j = 0; j < 2; j++) {
      vb[i][j] = (tb[i] * 27 + cb[i]) % mod[j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      h[i][j] = (h[i - 1][j] * prime[j] + va[i][j]) % mod[j];
    }
  }
}

long long get(int l, int r, int t) {
  long long ret = (h[r][t] - h[l - 1][t] * power[r - l + 1][t]) % mod[t];
  if(ret < 0) ret += mod[t];
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    char c;
    scanf("%d-%c", ta + i, &c);
    ca[i] = c - 'a' + 1;
  }
  for(int i = 1; i <= m; i++) {
    char c;
    scanf("%d-%c", tb + i, &c);
    cb[i] = c - 'a' + 1;
  }
  int tn = 1;
  for(int i = 2; i <= n; i++) {
    if(ca[i] == ca[tn]) {
      ta[tn] += ta[i];
    } else {
      ++tn;
      ta[tn] = ta[i];
      ca[tn] = ca[i];
    }
  }
  n = tn;
  
  int tm = 1;
  for(int i = 2; i <= m; i++) {
    if(cb[i] == cb[tm]) {
      tb[tm] += tb[i];
    } else {
      ++tm;
      tb[tm] = tb[i];
      cb[tm] = cb[i];
    }
  }
  m = tm;
  //printf("%d %d\n", n, m);
  
  long long ans = 0;
  if(m == 1) {
    for(int i = 1; i <= n; i++) {
      if(cb[1] == ca[i] && tb[1] <= ta[i]) {
        ans += ta[i] - tb[1] + 1;
      }
    }
  } else if(m == 2) {
    for(int i = 1; i + 1 <= n; i++) {
      if(cb[1] == ca[i] && cb[2] == ca[i + 1] && tb[1] <= ta[i] && tb[2] <= ta[i + 1]) {
        ans++;
      }
    }
  } else {
    init();
    long long key[2] = {};
    for(int i = 2; i < m; i++) {
      for(int j = 0; j < 2; j++) {
        key[j] = (key[j] * prime[j] + vb[i][j]) % mod[j];
      }
    }
    for(int i = 2; i + m - 2 <= n; i++) {
      long long val[2] = {};
      val[0] = get(i, i + m - 3, 0);
      val[1] = get(i, i + m - 3, 1);
      if(val[0] == key[0] && val[1] == key[1]
          && ca[i - 1] == cb[1] && ta[i - 1] >= tb[1]
          && ca[i + m - 2] == cb[m] && ta[i + m - 2] >= tb[m]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}