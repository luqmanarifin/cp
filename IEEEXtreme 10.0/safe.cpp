#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long PRIME = 71;
const long long mod = 2e9 + 89;

char s[N];
long long power[N];
long long has[26][N], all[N];

long long take(int l, int r, int at) {
  long long ret = (has[at][r] - has[at][l - 1] * power[r - l + 1]) % mod;
  if (ret < 0) ret += mod;
  return ret;
}

long long find(int l, int r) {
  long long ret = (all[r] - all[l - 1] * power[r - l + 1]) % mod;
  if (ret < 0) ret += mod;
  return ret;
}

struct segtree {
  segtree() {
    for (int i = 0; i < 26; i++) h[i].assign(N << 2, 0);
    val.assign(N << 2, 0);
    push.assign(N << 2, 0);
    add.assign(N << 2, 0);
  }
  void relaks(int p, int l, int r) {
    if (push[p]) {
      int mid = (l + r) >> 1;
      if (l < r) {
        push[p + p] = push[p];
        push[p + p + 1] = push[p] + mid + 1 - l;
        add[p + p] = 0;
        add[p + p + 1] = 0;
      }
      for (int i = 0; i < 26; i++) {
        h[i][p] = take(push[p], push[p] + r - l, i);
      }
      val[p] = find(push[p], push[p] + r - l);
      push[p] = 0;
    } 
    if (add[p]) {
      if (l < r) {
        add[p + p] += add[p];
        add[p + p + 1] += add[p];
      }
      val[p] = 0;
      long long* tmp = new long long[26];
      for (int i = 0; i < 26; i++) tmp[(i + add[p]) % 26] = h[i][p];
      for (int i = 0; i < 26; i++) h[i][p] = tmp[i];
      for (int i = 0; i < 26; i++) {
        val[p] += (i + 1) * h[i][p];
        val[p] %= mod;
      }
      add[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    int mid = (l + r) >> 1;
    val[p] = 0;
    for (int i = 0; i < 26; i++) {
      h[i][p] = (h[i][p + p] * (r - mid) + h[i][p + p + 1]) % mod;
      val[p] += (i + 1) * h[i][p];
      val[p] %= mod;
    }
  }
  void build(int p, int l, int r) {
    if (l == r) {
      h[s[l] - 'a'][p]++;
      val[p] = s[l] - 'a' + 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int p, int l, int r, int ll, int rr, int k) {
    relaks(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = k;
      add[p] = 0;
      relaks(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, k);
    update(p + p + 1, mid + 1, r, ll, rr, mid < ll? k : (l <= ll? k+mid+1-ll : k+mid+1-l));
    combine(p, l, r);
  }
  void add(int p, int l, int r, int ll, int rr) {
    relaks(p, l, r);
    if ()
  }
  vector<int> h[26], val;
  vector<int> push, add;
};

int main() {


  return 0;
}
