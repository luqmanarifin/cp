#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int a[N], h;

bool can(int x) {
  vector<int> b;
  for (int i = 0; i < x; i++) b.push_back(a[i]);
  sort(b.begin(), b.end());
  long long need = 0;
  for (int i = x - 1; i >= 0; i -= 2) {
    need += b[i];
  }
  // printf("%d need %lld\n", x, need);
  return need <= h;
}

int main() {
  int n;
  scanf("%d %d", &n, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int l = 1, r = n;
  while (l < r) {
    // printf("%d %d\n", l, r);
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
