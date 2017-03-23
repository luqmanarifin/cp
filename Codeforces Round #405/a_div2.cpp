#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  scanf("%I64d %I64d", &a, &b);
  int ans = 0;
  for (int i = 1; a <= b; i++) {
    ans = i;
    a *= 3;
    b *= 2;
  }
  cout << ans << endl;
  return 0;
}
