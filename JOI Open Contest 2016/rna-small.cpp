#include <bits/stdc++.h>

using namespace std;

const long long mod = 2e9 + 89;
const long long PRIME = 1000039;
const int N = 1e5 + 5;
int NUM;

struct node {
  node() {
    a = new long long[NUM];
    for(int i = 0; i < NUM; i++) {
      a[i] = 0;
    }
  }
  void insert(int i) {
    a[i / 64] |= (1LL << (i % 64));
  }
  long long* a;
};

char s[N], t[N];

void solve(int n, int m) {
  vector<long long> f[n], g[N];
  for(int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    long long cur = 0;
    for(int j = 0; j < len; j++) {
      cur = (cur * PRIME + s[j] - 'A' + 1) % mod;
      f[i].push_back(cur);
    }

    cur = 0;
    for(int j = len - 1; j >= 0; j--) {
      cur = (cur * PRIME + s[j] - 'A' + 1) % mod;
      g[i].push_back(cur);
    }
  }
  while(m--) {
    scanf("%s %s", s, t);
    int slen = strlen(s);
    int tlen = strlen(t);
    long long hl = 0;
    for(int j = 0; j < slen; j++) {
      hl = (hl * PRIME + s[j] - 'A' + 1) % mod;
    }

    long long hr = 0;
    for(int j = tlen - 1; j >= 0; j--) {
      hr = (hr * PRIME + t[j] - 'A' + 1) % mod;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(slen <= f[i].size() && tlen <= g[i].size()) {
        if(hl == f[i][slen - 1] && hr == g[i][tlen - 1]) {
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
}

// f dari depan, g dari belakang
map<long long, node> f[N], g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(n <= 5000 && m <= 5000) {
    solve(n, m);
    return 0;
  }
  NUM = n / 64 + (n % 64? 1 : 0);
  int ml = 0;
  for(int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    ml = max(ml, len);
    long long cur = 0;
    for(int j = 0; j < len; j++) {
      cur = (cur * PRIME + s[j] - 'A' + 1) % mod;
      if(f[j + 1].count(cur)) {
        f[j + 1][cur].insert(i);
      } else {
        node nod;
        nod.insert(i);
        f[j + 1][cur] = nod;
      }
    }

    cur = 0;
    for(int j = len - 1; j >= 0; j--) {
      cur = (cur * PRIME + s[j] - 'A' + 1) % mod;
      if(g[len - j].count(cur)) {
        g[len - j][cur].insert(i);
      } else {
        node nod;
        nod.insert(i);
        g[len - j][cur] = nod;
      }
    }
  }
  while(m--) {
    scanf("%s %s", s, t);
    int slen = strlen(s);
    int tlen = strlen(t);
    if(slen > ml || tlen > ml) {
      puts("0");
      continue;
    }
    long long hl = 0;
    for(int j = 0; j < slen; j++) {
      hl = (hl * PRIME + s[j] - 'A' + 1) % mod;
    }

    long long hr = 0;
    for(int j = tlen - 1; j >= 0; j--) {
      hr = (hr * PRIME + t[j] - 'A' + 1) % mod;
    }

    node l = f[slen][hl];
    node r = g[tlen][hr];
    int ans = 0;
    for(int i = 0; i < NUM; i++) {
      long long d = (l.a[i] & r.a[i]);
      if(d) {
        ans += __builtin_popcountll(d);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
