#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int PRIME = 71;
const long long mod = 2e9 + 89;

struct node {
  node() {
    h = 0;
    add = 0;
    len = 0;
    val.assign(26, 0);
  }
  node(node* lef, node* rig, long long h, int len) : lef(lef), rig(rig), h(h), len(len), add(0) {
    val.assign(26, 0);
  }
  node* lef;
  node* rig;
  long long h;
  int add, len;
  vector<long long> val;
};

long long power[N];

node* null;
node* root;
int n;
char s[N];

void relaks(node* now) {
  if (now->add) {
    if (now->len > 1) {
      now->lef->add += now->add;
      now->rig->add += now->add;
    }
    int* nim = new int[26];
    for (int i = 0; i < 26; i++) {
      nim[(i + now->add) % 26] = now->val[i];
    }
    for (int i = 0; i < 26; i++) {
      now->val[i] = nim[i];
    }
    now->h = 0;
    for (int i = 0; i < 26; i++) {
      now->h += (i + 1) * now->val[i];
      now->h %= mod;
    }
    now->add = 0;
  }
}

void combine(node* now) {
  if (now->len == 1) return; 
  for (int i = 0; i < 26; i++) {
    now->val[i] = (now->lef->val[i] * power[now->rig->len] + now->rig->val[i]) % mod;
  }
  now->h = (now->lef->h * power[now->rig->len] + now->rig->h) % mod;
}

void build(node* now, int l, int r) {
  if (l == r) {
    now->lef = now->rig = null;
    now->h = (s[l] - 'a' + 1);
    now->add = 0;
    now->len = 1;
    now->val[s[l] - 'a'] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(now->lef = new node(), l, mid);
  build(now->rig = new node(), mid + 1, r);
  combine(now);
  now->add = 0;
  now->len = now->lef->len + now->rig->len;
}

node* ask(node* now, int l, int r, int at, int len) {
  relaks(now);
  if (l < r) {
    relaks(now->lef);
    relaks(now->rig); 
  }
  combine(now);
  if (l == at && now->len <= len) {
    return now;
  }
  int mid = (l + r) >> 1;
  if (at <= mid) {
    return ask(now->lef, l, mid, at, len);
  } else {
    return ask(now->rig, mid + 1, r, at, len);
  }
}

node* update(node* now, int l, int r, int ll, int rr, int k) {
  relaks(now);
  if (l < r) {
    relaks(now->lef);
    relaks(now->rig); 
  }
  if (l == ll && rr == r) {
    node* ret = ask(root, 1, n, k, now->len);
    if (ret->len == now->len) {
      now = ret;
    } else {
      int mid = (l + r) >> 1;
      now->lef = update(now->lef, l, mid, l, mid, k);
      now->rig = update(now->rig, mid + 1, r, mid + 1, r, k + mid + 1 - ll);
      combine(now);
    }
    return now;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) {
    now->lef = update(now->lef, l, mid, ll, min(mid, rr), k);
  }
  if (mid < rr) {
    now->rig = update(now->rig, mid + 1, r, max(ll, mid + 1), rr, ll <= mid? k + mid + 1 - ll : k);
  }
  combine(now);
  return now;
}

void add(node* now, int l, int r, int ll, int rr) {
  relaks(now);
  if (l < r) {
    relaks(now->lef);
    relaks(now->rig); 
  }
  if (l == ll && rr == r) {
    now->add++;
    relaks(now);
    return;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) {
    add(now->lef, l, mid, ll, min(mid, rr));
  }
  if (mid < rr) {
    add(now->rig, mid + 1, r, max(ll, mid + 1), rr);
  }
  combine(now);
}

long long find(node* now, int l, int r, int ll, int rr) {
  relaks(now);
  if (l < r) {
    relaks(now->lef);
    relaks(now->rig); 
  }
  combine(now);
  if (l == ll && rr == r) {
    return now->h;
  }
  int mid = (l + r) >> 1;
  long long ret = 0;
  if (ll <= mid) {
    ret = find(now->lef, l, mid, ll, min(mid, rr));
  }
  if (mid < rr) {
    long long val = find(now->rig, mid + 1, r, max(ll, mid + 1), rr);
    int len = rr - mid;
    ret = (ret * power[len] + val) % mod;
  }
  return ret;
}

int main() {
  null = new node();
  null->lef = null;
  null->rig = null;
  power[0] = 1;
  for (int i = 0; i < N; i++) power[i] = power[i - 1] * PRIME % mod;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  build(root = new node(), 1, n);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, k;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      scanf("%d", &k);
      long long lef = find(root, 1, n, l, r);
      long long rig = find(root, 1, n, k, k + r - l);
      puts(lef == rig? "Y" : "N");
    } else if (t == 2) {
      scanf("%d", &k);
      update(root, 1, n, l, r, k);
    } else {
      add(root, 1, n, l, r);
    }
  }

  return 0;
}
