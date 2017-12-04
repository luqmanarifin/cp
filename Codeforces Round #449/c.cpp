/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

struct item {
  item() {}
  item(int l, int r, long long v) : l(l), r(r), v(v) {}
  bool operator<(const item& other) const {
    if (l != other.l) return l < other.l;
    if (r != other.r) return r < other.r;
    return v < other.v;
  }
  bool operator==(const item& other) const {
    return l == other.l && r == other.r && v == other.v;
  }
  int l, r;
  long long v;
};

long long n, m, seed, vmax;
set<item> s;
long long a[N];

long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}

void build() {
  for (int i = 1; i <= n; i++) {
    s.insert(item(i, i, a[i]));
  }
}

void add(int l, int r, int x) {
  vector<item> rem, ins;
  auto it = s.lower_bound(item(l + 1, -1, -1));
  it--;
  while (it != s.end() && it->l <= r) {
    int lef = max(l, it->l);
    int rig = min(r, it->r);
    long long val = it->v + x;
    rem.push_back(*it);
    ins.push_back(item(lef, rig, val));
    if (it->l < lef) {
      ins.push_back(item(it->l, lef - 1, it->v));
    }
    if (rig < it->r) {
      ins.push_back(item(rig + 1, it->r, it->v));
    }
    it++;
  }
  for (auto i : rem) s.erase(i);
  for (auto i : ins) s.insert(i);
}

void change(int l, int r, int x) {
  vector<item> rem, ins;
  auto it = s.lower_bound(item(l + 1, -1, -1));
  it--;
  ins.push_back(item(l, r, x));
  while (it != s.end() && it->l <= r) {
    int lef = max(l, it->l);
    int rig = min(r, it->r);
    if (it->l < lef) {
      ins.push_back(item(it->l, lef - 1, it->v));
    }
    if (rig < it->r) {
      ins.push_back(item(rig + 1, it->r, it->v));
    }
    rem.push_back(*it);
    it++;
  }
  for (auto i : rem) s.erase(i);
  for (auto i : ins) s.insert(i);
}

long long ke(int l, int r, int x) {
  // value, banyak
  vector<pair<long long, int>> all;
  auto it = s.lower_bound(item(l + 1, -1, -1));
  it--;
  while (it != s.end() && it->l <= r) {
    int lef = max(l, it->l);
    int rig = min(r, it->r);
    all.emplace_back(it->v, rig - lef + 1);
    it++;
  }
  sort(all.begin(), all.end());
  for (auto i : all) {
    if (x <= i.second) return i.first;
    x -= i.second;
  }
  assert(false);
}

long long power(long long a, long long b, long long mod) {
  if (b == 0) return 1 % mod;
  long long tmp = power(a, b / 2, mod);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

int sumpower(int l, int r, int x, int y) {
  long long ret = 0;
  auto it = s.lower_bound(item(l + 1, -1, -1));
  it--;
  while (it != s.end() && it->l <= r) {
    int lef = max(l, it->l);
    int rig = min(r, it->r);
    long long add = power(it->v % y, x, y) * (rig - lef + 1) % y;
    ret = (ret + add) % y;
    it++;
  }
  return ret;
}

main() {
  scanf("%I64d %I64d %I64d %I64d", &n, &m, &seed, &vmax);
  for (int i = 1; i <= n; i++) a[i] = (rnd() % vmax) + 1;
  build();
  while (m--) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    int x, y;
    if (l > r) swap(l, r);
    if (op == 3) {
      x = (rnd() % (r - l + 1)) + 1;
    } else {
      x = (rnd() % vmax) + 1;
    }
    if (op == 4) {
      y = (rnd() % vmax) + 1;
    }
    
    if (op == 1) {
      add(l, r, x);
    } else if (op == 2) {
      change(l, r, x);
    } else if (op == 3) {
      printf("%I64d\n", ke(l, r, x));
    } else {
      printf("%I64d\n", sumpower(l, r, x, y));
    }
  }
  return 0;
}
