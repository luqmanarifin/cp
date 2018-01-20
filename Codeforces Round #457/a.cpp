#include <bits/stdc++.h>

using namespace std;

bool lucky(int a, int b) {
  return a / 10 == 7 || a % 10 == 7 || b / 10 == 7 || b % 10 == 7;
}

int main() {
  int x, a, b;
  scanf("%d %d %d", &x, &a, &b);
  int now = a * 60 + b;
  int mod = 24 * 60;
  int cur = now;
  int ans = 0;
  while (!lucky(cur / 60, cur % 60)) {
    cur = (cur - x + mod) % mod;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
