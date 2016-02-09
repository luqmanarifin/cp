#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, a[i] * (n - i));
  }
  cout << ans << endl;
  return 0;
}
