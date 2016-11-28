#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

map<int, bool> done;
vector<int> ans;
int a[N], n;

bool can(int t) {
  done.clear();
  ans.clear();
  for (int i = n - 1; i >= 0; i--) {
    int now = a[i];
    while (now > t) now /= 2;
    while (now && done[now]) now /= 2;
    if (now == 0) return 0;
    ans.push_back(now);
    done[now] = 1;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int l = 1, r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  assert(can(l));
  for (auto it : ans) printf("%d ", it);
  return 0;
}
