#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
int n, m;
bool done[N], got[N];

bool can(int to) {
  memset(done, 0, sizeof(done));
  memset(got, 0, sizeof(got));
  for (int i = to; i >= 1; i--) {
    if (a[i] && !done[a[i]]) {
      got[i] = 1;
      done[a[i]] = 1;
    }
  }
  int all = 0, now = 0;
  for (int i = 1; i <= to; i++) {
    if (got[i] && now >= b[a[i]]) {
      all++;
      now -= b[a[i]];
    } else {
      now++;
    }
  }
  return all == m;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (can(l)) {
    cout << l << endl;
  } else {
    puts("-1");
  }
  return 0;
}
