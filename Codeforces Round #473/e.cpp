
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; i *= 2) {
    long long ada = n / i + (n % i? 1 : 0);
    ans += i * (ada / 2);
  }
  cout << ans << endl;
  return 0;
}
