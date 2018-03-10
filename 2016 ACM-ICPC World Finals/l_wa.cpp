#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int inf = 2e9;

int h[N], gain[N];
int num[N << 2], n;
long long sum;

void build(int p, int l, int r) {
  if (l == r) {
    num[p] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  if (gain[num[p + p]] <= gain[num[p + p + 1]]) {
    num[p] = num[p + p + 1];
  } else {
    num[p] = num[p + p];
  }
}

void remove(int p, int l, int r, int at) {
  if (l == r) {
    num[p] = N - 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (at <= mid) {
    remove(p + p, l, mid, at);
  } else {
    remove(p + p + 1, mid + 1, r, at);
  }
  if (gain[num[p + p]] <= gain[num[p + p + 1]]) {
    num[p] = num[p + p + 1];
  } else {
    num[p] = num[p + p];
  }
}

int find(int p, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) return num[p];
  int mid = (l + r) >> 1, ret = N - 1;
  if (ll <= mid) {
    int f = find(p + p, l, mid, ll, rr);
    if (gain[ret] <= gain[f]) {
      ret = f;
    }
  }
  if (mid < rr) {
    int f = find(p + p + 1, mid + 1, r, ll, rr);
    if (gain[ret] <= gain[f]) {
      ret = f;
    }
  }
  return ret;
}

bool can(long long x, bool debug = 0) {
  build(1, 0, n - 1);
  long long cap = sum + x;
  for (int i = 0; i < n; i++) {
    long long now = cap - sum;
    int p = upper_bound(h, h + n, now) - h;
    //if (debug) printf("caps %lld until %d\n", now, p - 1);
    if (p == 0) return 0;
    int f = find(1, 0, n - 1, 0, p - 1);
    if (f == N - 1) return 0;
    cap += gain[f];
    remove(1, 0, n - 1, f);
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v.emplace_back(a, b - a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    h[i] = v[i].first;
    gain[i] = v[i].second;
    //printf("%d gain %d\n", i, gain[i]);
    sum += h[i];
  }
  gain[N - 1] = -inf;
  long long l = 0, r = 1e15;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  can(l, 1);
  cout << l << endl;
  return 0;
}
