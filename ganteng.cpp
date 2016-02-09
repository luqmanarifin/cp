#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;
const long long inf = 1e18;

int a[N];
int b[N];

main() {
  int n;
  scanf("%lld", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  sort(a, a + n);
  for(int i = n - 2; i >= 0; i--) {
    b[i] = a[i + 1] - a[i];
  }
  for(int i = n - 3; i >= 0; i--) {
    b[i] = max(b[i], b[i + 1]);
  }
  long long ans = inf;
  for(int i = 1; i < n - 1; i++) {
    int pre = a[i - 1] - a[0];
    int add = (a[n - 1] - a[i]) - b[i];
    if(pre + add < ans) {
      ans = pre + add;
    }
  }
  cout << ans << endl;
  return 0;
}
