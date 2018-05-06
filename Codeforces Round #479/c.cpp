#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], n;

int find(int x) {
  return upper_bound(a, a + n, x) - a;
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int l = 1, r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (find(mid) < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (find(l) == k) {
    cout << l << endl;
  } else {
    puts("-1");
  }

  return 0;
}
