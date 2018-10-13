#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int n, m, k;

bool can(int st) {
  int ori = st;
  for (int i = 0; i < m; i++) {
    long long now = 0;
    while (st < n && now + a[st] <= k) {
      now += a[st];
      st++;
    }
    // printf("terisi %d\n", now);
  }
  // printf("ori %d until %d\n", ori, st);
  return st == n;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << n - l << endl;
  return 0;
}
