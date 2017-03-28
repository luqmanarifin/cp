#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N], n;
vector<int> seg[N];

vector<int> all, dp;

inline int get(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

void solve(int k) {
  cout << k << endl;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long l = 1, r = 1e9;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if ((k + 1) * mid < a[i]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    ans += l;
  }
  cout << ans << endl;
}

map<int, int> cnt;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int MN = 2e9;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        seg[i].push_back(a[i] / j);
        seg[i].push_back(a[i] / j - 1);
      } else {
        seg[i].push_back(a[i] / j);
      }
    }
    sort(seg[i].begin(), seg[i].end());
    seg[i].resize(distance(seg[i].begin(), unique(seg[i].begin(), seg[i].end())));
    MN = min(MN, a[i]);
    for (auto it : seg[i]) {
      printf("%d ", it);
      cnt[-it]++;
    }
    printf("\n");
  }
  cnt[-MN] = n;
  for (auto it : cnt) {
    if (it.second == n) {
      solve(-it.first);
      return 0;
    }
  }
  return 0;
}
