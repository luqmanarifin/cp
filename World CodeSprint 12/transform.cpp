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

const long long mod = 1e9 + 7;
const int N = 2e5 + 5;

inline void simple(long long& val) {
  if (val >= mod) val -= mod;
}

struct segtree {
  segtree(int n) : n(n) {
    x.assign(n << 2, 0);
    y.assign(n << 2, 0);
    px.assign(n << 2, 0);
    py.assign(n << 2, 0);
    ans.assign(n << 2, 0);
  }
  void relax(int p, int l, int r) {
    if (px[p] || py[p]) {
      if (l < r) {
        if (px[p]) {
          px[p + p] = px[p];
          px[p + p + 1] = px[p];
        }
        if (py[p]) {
          py[p + p] = py[p];
          py[p + p + 1] = py[p];
        }
      }
      if (px[p] && py[p]) {
        x[p] = px[p] * (r - l + 1) % mod;
        y[p] = py[p] * (r - l + 1) % mod;
        ans[p] = px[p] * py[p] % mod * (r - l + 1) % mod;
      } else if (px[p]) {
        x[p] = px[p] * (r - l + 1) % mod;
        ans[p] = px[p] * y[p] % mod;
      } else if (py[p]) {
        y[p] = py[p] * (r - l + 1) % mod;
        ans[p] = x[p] * py[p] % mod;
      } else {
        assert(0);
      }
      px[p] = py[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    x[p] = x[p + p] + x[p + p + 1];
    y[p] = y[p + p] + y[p + p + 1];
    ans[p] = ans[p + p] + ans[p + p + 1];
    simple(x[p]);
    simple(y[p]);
    simple(ans[p]);
  }
  void change_x(int l, int r, long long val) {
    change_x(1, 0, n - 1, l, r, val);
  }
  void change_x(int p, int l, int r, int ll, int rr, long long val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      px[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    change_x(p + p, l, mid, ll, rr, val);
    change_x(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  void change_y(int l, int r, long long val) {
    change_y(1, 0, n - 1, l, r, val);
  }
  void change_y(int p, int l, int r, int ll, int rr, long long val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      py[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    change_y(p + p, l, mid, ll, rr, val);
    change_y(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  long long find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return ans[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    long long ret = find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    simple(ret);
    return ret;
  }
  int n;
  vector<long long> x, y, ans, px, py;
};

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long half;

long long arith(long long a, long long b, long long n) {
  n %= mod;
  return (2*a + (n - 1)*b%mod) % mod * n % mod * half % mod;
}

long long sum(long long l, long long r) {
  return arith(l, 1, r - l + 1);
}

long long sum(long long n) {
  return sum(1, n);
}

long long solve(long long n, long long m) {
  return arith(sum(m), m, n);
}

long long polos(long long n) {
  return n * (n + 1) / 2;
}

long long a[N], pre[N], rev[N];

int main() {
#define int long long
  half = inv(2);
  //for (int i = 1; i <= 10; i++) printf("%lld\n", arith(1, 1, i));
  
  int n;
  scanf("%lld", &n);
  vector<pair<long long, int>> p;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    p.emplace_back(a[i], i);
    pre[i] = a[i];
    if (i) pre[i] = max(pre[i], pre[i - 1]);
  }
  rev[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) rev[i] = max(rev[i + 1], a[i]);
  
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  set<int> s;
  s.insert(-1);
  s.insert(n);
  
  long long ans = 0;
  for (int i = 0; i < p.size(); i++) {
    auto upp = s.lower_bound(p[i].second);
    auto low = upp; low--;
    int NN = p[i].second - *low;
    int MM = *upp - p[i].second;
    long long ada = solve(NN, MM);
    if (i == 0) {
      ada -= n;
    }
    ans += ada * p[i].first;
    ans %= mod;
    s.insert(p[i].second);
  }
  long long tot = sum(sum(n));
  tot -= 1LL * (n - 1) * n * (n + 1) / 6 % mod;
  tot -= sum(n - 1);
  tot %= mod;
  if (tot < 0) tot += mod;
  
  // segment tree part
  segtree seg(n);
  for (int i = 0; i < n; i++) seg.change_x(i, i, pre[i]);
  for (int i = n - 1; i >= 3; i--) {
    int at = lower_bound(pre, pre + n, rev[i]) - pre;
    if (at > 0) {
      at--;
      seg.change_x(0, at, rev[i]);
      pre[at] = rev[i];
    }
    int j = n - i;
    seg.change_y(j, n - 1, j);
    ans += seg.find(1, i - 2);
    simple(ans);
    
    if (j < i - 2) {
      tot -= sum(j) + j * (i - 2 - j);
    } else {
      tot -= sum(i - 2);
    }
    tot %= mod;
  }
  
  // all range
  ans += tot * p[0].first;
  ans %= mod;
  if (ans < 0) ans += mod;
  
  cout << ans << endl;
  return 0;
}
