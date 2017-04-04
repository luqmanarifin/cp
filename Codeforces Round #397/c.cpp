#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, a, b;
  scanf("%d %d %d", &k, &a, &b);
  int ans = a / k + b / k;
  if (ans == 0) ans = -1;
  if (a % k && b < k) {
    puts("-1");
    return 0;
  }
  if (b % k && a < k) {
    puts("-1");
    return 0;
  }
  cout << ans << endl;
  return 0;
}
