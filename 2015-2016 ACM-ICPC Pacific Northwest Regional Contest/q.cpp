#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 1e9;
  for(int i = 0; i < n; i++) {
    ans = min(ans, a[i] + a[n - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}