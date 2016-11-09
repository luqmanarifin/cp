#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ans = max(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
}
