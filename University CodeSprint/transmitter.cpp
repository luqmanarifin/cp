#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() { 
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 0;
  int i = 0;
  while (i < n) {
    ans++;
    i = upper_bound(a, a + n, a[i] + k) - a - 1;
    i = upper_bound(a, a + n, a[i] + k) - a;
  }
  cout << ans << endl;
  return 0;
}
