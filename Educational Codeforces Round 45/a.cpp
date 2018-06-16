#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  long long low = n / m;
  long long upp = low + 1;
  cout << min((upp * m - n) * a, (n - low * m) * b) << endl;

  return 0;
}
