#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

long long n, f, t, l;
long long d[N], c[N], cheap[N];
long long num[N << 2];

bool feasible() {
  int now = t;
  for (int i = 1; i <= n; i++) {
    if (now < d[i] - d[i - 1]) {
      return 0;
    }
    now = f;
  }
  return 1;
}

void build(int p, int l, int r) {
  if (l == r) {
    num[p] = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p] = min(num[p + p], num[p + p + 1]);
}

int find(int p, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) return num[p];
  if (r < ll || rr < l) return 1e9;
  int mid = (l + r) >> 1;
  return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
}

int find(int l, int r) {
  return find(1, 1, n, l, r);
}

bool can(long long money) {
  long long now = t;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    long long dist = d[i] - d[i - 1];
    if (now < dist) {
      long long buy = dist - now;
      money -= cheap[i - 1] * buy;
      
      now += buy;
      last = i;
    }
    if (money < 0) return 0;
    now -= dist;
  }
  return 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%lld %lld %lld %lld", &n, &f, &t, &l);
    vector<pair<long long, long long>> p;
    for (int i = 1; i <= n; i++) {
      scanf("%lld %lld", d + i, c + i);
      p.emplace_back(d[i], c[i]);
    }
    sort(p.begin(), p.end());
    for (int i = 1; i <= n; i++) {
      d[i] = p[i - 1].first;
      c[i] = p[i - 1].second;
    }
    
    ++n;
    d[n] = l;
    build(1, 1, n);
    if (!feasible()) {
      puts("-1");
      continue;
    }
    long long l = 0, r = 1e18;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
      puts("");
    }
    assert(can(l));
    puts("");
    printf("%lld\n", l);
  }

  return 0;
}
