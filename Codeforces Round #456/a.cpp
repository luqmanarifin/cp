#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x, y, z;
  scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
  long long needYellow = 1LL * x * 2 + y;
  long long needBlue = y + 3LL * z;
  long long ans = 0;
  if (needYellow > a) ans += abs(a - needYellow);
  if (needBlue > b) ans += abs(b - needBlue);
  cout << ans << endl;
  return 0;
}
