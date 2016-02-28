#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 0;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] >= a[i]) {
      ans += a[i - 1] + 1 - a[i];
      a[i] = a[i - 1] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
