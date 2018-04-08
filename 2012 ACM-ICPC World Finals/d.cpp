#include <bits/stdc++.h>

using namespace std; 

const int p = 29, mod = 1e9 + 7;
const int N = 1e5 + 5, M = 102;
const int inf = 1e7;
int fib[M];

long long powmod(long long b, long long pw, long long m) {
  long long r = 1;
  for (; pw; pw >>= 1, b = b * b % m)
    if (pw & 1)
      r = r * b % m;
  return r;
}

long long pp[N];

struct hashh {
  long long v;
  int len;
  hashh() : v(0), len(0) {}
  hashh(int c) {
    v = c;
    len = 1;
  }
  hashh operator+(hashh h) {
    hashh ret;
    ret.v = (v + h.v * pp[len]) % mod;
    if (ret.v < 0) ret.v += mod;
    ret.len = len + h.len;
    return ret;
  }
  bool operator==(hashh h) {
    return (h.v == v) && len == h.len;
  }
  
};

hashh dl[M][N], dr[M][N];
bool visl[M][N], visr[M][N];

hashh getLeft(int n, int k) {
  if (visl[n][k])
    return dl[n][k];
  if (k == 0) return hashh();
  if (n <= 1)
    return hashh(n+1);
  visl[n][k] = 1;
  dl[n][k] = getLeft(n-1, min(k, fib[n-1]));
  if (dl[n][k].len < k) {
    int need = k- dl[n][k].len;
    dl[n][k] = dl[n][k] + getLeft(n-2, need);
  }
  return dl[n][k];
}

hashh getRight(int n, int k) {
  if (visr[n][k])
    return dr[n][k];
  if (k == 0) return hashh();
  if (n <= 1)
    return hashh(n+1);
  visr[n][k] = 1;
  dr[n][k] = getRight(n-2, min(k, fib[n-2]));
  if (dr[n][k].len < k) {
    int need = k-dr[n][k].len;
    dr[n][k] = getRight(n-1, need) + dr[n][k];
  }
  return dr[n][k];
}

long long cnt[M];

char s[N];

int main() {
  pp[0] = 1;
  for (int i = 1; i < N; ++i)
    pp[i] = pp[i-1] * p % mod;
  fib[0] = fib[1] = 1;
  for (int i = 2; i < M; ++i) {
    fib[i] = (fib[i-1] + fib[i-2]);
    if (fib[i] > inf)
      fib[i] = inf;
  }
  int n;
  int tc = 1;
  while (scanf("%d %s", &n, s) != EOF) {
    int len = strlen(s);
    hashh h;
    hashh satu(2), nol(1);
    for (int i = 0; i < len; ++i) {
      h = h + ((s[i] == '1') ? satu : nol);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= min(len, fib[i]); ++j)
        visl[i][j] = visr[i][j] = 0;
    }
    cnt[0] = 0;
    cnt[1] = 0;
    if (len == 1) {
      cnt[s[0]-'0']++;
    }
    for (int i = 2; i <= n; ++i) {
      cnt[i] = cnt[i-1] + cnt[i-2];
      for (int le = 1; le <= min(len, fib[i-1]); ++le) {
        int ri = len - le;
        if (ri <= 0 || ri > fib[i-2]) continue;
        hashh res = (getRight(i-1, le) + getLeft(i-2, ri));
        hashh rr = getRight(i-1, le), ll = getLeft(i-2, ri);
        //~ cerr << rr.v << " " << ll.v << " " << rr.len << " " << ll.len << endl;
        //~ cerr << i << " " << le << " " << ri << " " << res.v << " " << res.len << " c " << h.v << " " << h.len << endl;
        cnt[i] += res == h;
      }
      //~ cerr << i << " " << cnt[i] << endl;
    }
    printf("Case %d: %lld\n", tc, cnt[n]);
    ++tc;
  }
  return 0;
}
