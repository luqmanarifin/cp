#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5 + 5;
const int mod = 1e9 + 7;
const int BIG = 1e6 + 5;

struct node {
  node() {
    lef = rig = NULL;
    k = -1;
  }
  ~node() {
    if (lef) delete lef;
    if (rig) delete rig;
  }
  node* lef;
  node* rig;
  int k;
};

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long dua[BIG], invd[BIG];

node* root;
int now;          // waktu sekarang
long long add;    // nambah berapa
long long nodes;  // berapa node sekarang
char s[BIG];

void boom(char *s) {
  int n = strlen(s);
  node* cur = root;
  int last = 0;
  long long sub = (dua[now + 1] - 1 + mod) % mod;
  long long active = dua[now + 1];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (cur->lef == NULL) cur->lef = new node();
      cur = cur->lef;
    } else {
      if (cur->rig == NULL) cur->rig = new node();
      cur = cur->rig;
    }
    if (cur->k != -1 && cur->k > last) {
      int elapsed = now - cur->k;
      sub = (dua[elapsed] - 1 + mod) % mod;
      active = dua[elapsed];
      last = cur->k;
    } else {
      sub = (sub - 1 + mod) * invd[1] % mod;
      active = active * invd[1] % mod;
    }
  }
  nodes -= sub;
  nodes %= mod;
  if (nodes < 0) nodes += mod;
  add -= active;
  add++;
  add %= mod;
  if (add < 0) add += mod;
  cur->k = now;
}

main() {
  dua[0] = invd[0] = 1;
  for (int i = 1; i < BIG; i++) {
    dua[i] = dua[i-1] * 2 % mod;
    invd[i] = inv(dua[i]);
  }
  
  int t;
  scanf("%lld", &t);
  while (t--) {
    root = new node();
    int q;
    scanf("%lld", &q);
    now = 0;
    add = 2;
    nodes = 1;
    while (q--) {
      int cmd;
      scanf("%lld", &cmd);
      if (cmd == 1) {
        int v;
        scanf("%lld", &v);
        nodes += add * (dua[v] - 1);
        nodes %= mod;
        now += v;
        add = add * dua[v] % mod;
      } else {
        scanf("%s", s);
        boom(s);
      }
      printf("%lld\n", nodes);
    }
    
    delete root;
  }

  return 0;
}
