#include <bits/stdc++.h>

using namespace std;

int d, t, l, e;

int main() {
  scanf("%d %d %d %d", &d, &t, &l, &e);
  int a = min(min(d, l), e);
  long long ans = 256LL * a;
  d -= a;
  l -= a;
  e -= a;
  int b = min(d, t);
  ans += 32LL * b;
  cout << ans << endl;

  return 0;
}
