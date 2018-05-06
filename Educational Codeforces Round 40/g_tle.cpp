
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long bit[N];
int a[N];
int n, R;
long long k;

long long find(int i) {
  long long ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

void add(int i, long long v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}

bool can(long long x) {
  long long need = 0;
  vector<pair<int, long long>> st;
  for (int i = 1; i <= n; i++) {
    long long now = find(i);
    if (now < x) {
      int at = min(n, i + R);
      int l = max(1, at - R);
      int r = min(n, at + R);
      add(l, x - now);
      add(r + 1, now - x);
      st.emplace_back(l, x - now);
      st.emplace_back(r + 1, now - x);
      need += x - now;
    }
    if (need > k) {
      for (auto it : st) add(it.first, -it.second);
      return 0;
    }
  }
  for (auto it : st) add(it.first, -it.second);
  return 1;
}

int main() {
  scanf("%d %d %lld", &n, &R, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int l = max(1, i - R);
    int r = min(n, i + R);
    add(l, a[i]);
    add(r + 1, -a[i]);
  }
  long long l = 0, r = 2e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
