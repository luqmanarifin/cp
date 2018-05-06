
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  int ans = 0;
  while (x <= y) {
    ans++;
    x *= 2;
  }
  cout << ans << endl;
  return 0;
}
