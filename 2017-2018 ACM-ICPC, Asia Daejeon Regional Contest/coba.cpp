#include <bits/stdc++.h>

using namespace std;

long long ans;

void solve(int n) {
  if (n == 1) return;
  int half = n / 2;
  ans += 1LL * half * (n - half);
  solve(half);
  solve(n - half);
}

int main() {
  int n = 5000;
  solve(n);
  cout << ans << endl;
  return 0;
}
