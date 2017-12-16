/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAGIC = 41;
const long long mod = 1e9;

long long fact[MAGIC];
int a[N];

int cnt[N << 2][MAGIC];
int lazy[N << 2];
long long ans[N << 2];

void combine(int p, int l, int r) {
  for (int i = 0; i < MAGIC; i++) {
    cnt[p][i] = cnt[p + p][i] + cnt[p + p + 1][i];
  }
  ans[p] = ans[p + p] + ans[p + p + 1];
  if (ans[p] >= mod) ans[p] -= mod;
}

void relax(int p, int l, int r) {
  if (lazy[p]) {
    if (l < r) {
      lazy[p + p] += lazy[p];
      lazy[p + p + 1] += lazy[p];
    }
    for (int i = MAGIC - 1; i >= lazy[p]; i--) cnt[p][i] = cnt[p][i - lazy[p]];
    for (int i = min(MAGIC - 1, lazy[p] - 1); i >= 0; i--) cnt[p][i] = 0;
    ans[p] = 0;
    for (int i = 0; i < MAGIC; i++) {
      ans[p] += fact[i] * cnt[p][i];
      ans[p] %= mod;
    }
    lazy[p] = 0;
  }
}

void build(int p, int l, int r) {
  if (l == r) {
    if (a[l] < MAGIC) {
      cnt[p][a[l]]++;
      ans[p] = fact[a[l]];
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  combine(p, l, r);
}

void add(int p, int l, int r, int ll, int rr) {
  relax(p, l, r);
  if (ll <= l && r <= rr) {
    lazy[p]++;
    relax(p, l, r);
    return;
  }
  if (r < ll || rr < l) return;
  int mid = (l + r) >> 1;
  add(p + p, l, mid, ll, rr);
  add(p + p + 1, mid + 1, r, ll, rr);
  combine(p, l, r);
}

long long find(int p, int l, int r, int ll, int rr) {
  relax(p, l, r);
  if (ll <= l && r <= rr) return ans[p];
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  long long ret = find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
  combine(p, l, r);
  return (ret >= mod? ret - mod : ret);
}

void change(int p, int l, int r, int at, int v) {
  relax(p, l, r);
  if (at < l || r < at) return;
  if (l == r) {
    for (int i = 0; i < MAGIC; i++) cnt[p][i] = 0;
    ans[p] = 0;
    if (v < MAGIC) {
      cnt[p][v] = 1;
      ans[p] = fact[v];
    }
    return;
  }
  int mid = (l + r) >> 1;
  change(p + p, l, mid, at, v);
  change(p + p + 1, mid + 1, r, at, v);
  combine(p, l, r);
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < MAGIC; i++) fact[i] = fact[i - 1] * i % mod;
  //for (int i = 1; i < MAGIC; i++) printf("%d: %lld\n", i, fact[i]);
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      add(1, 1, n, l, r);
    } else if (t == 2) {
      printf("%lld\n", find(1, 1, n, l, r));
    } else {
      change(1, 1, n, l, r);
    }
    //for (int i = 1; i <= n; i++) printf("%lld ", find(1, 1, n, i, i)); printf("\n");
  }

  return 0;
}
