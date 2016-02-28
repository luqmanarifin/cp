#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int l, r;
  scanf("%d %d", &l, &r);
  long long ans = 0;
  for(int i = l; i <= r; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
