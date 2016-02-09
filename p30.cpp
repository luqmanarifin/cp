#include <bits/stdc++.h>

using namespace std;

int a[55];

int main() {
  int n;
  int ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    if(i % 2) ans += a[i];
    else ans -= a[i];
  }
  cout << abs(ans) << endl;
  return 0;
}
