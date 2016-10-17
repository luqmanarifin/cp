#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long pol = max(a, max(b, c)) - 1;
  long long ans = 0;
  if (a < pol) ans += pol - a;
  if (b < pol) ans += pol - b;
  if (c < pol) ans += pol - c;
  cout << ans << endl;
  return 0;
}
