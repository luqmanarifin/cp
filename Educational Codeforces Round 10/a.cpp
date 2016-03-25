#include <bits/stdc++.h>

using namespace std;

int main() {
  long long h1, h2, a, b;
  scanf("%I64d %I64d %I64d %I64d", &h1, &h2, &a, &b);
  long long bef = h1;
  h1 -= 4 * a;
  long long ans = 0;
  while(1) {
    if(h1 + 12 * a >= h2) {
      cout << ans << endl;
      return 0;
    }
    h1 += 12 * (a - b);
    bef = h1;
    ans++;
    if(a <= b) break;
  }
  puts("-1");
  return 0;
}
