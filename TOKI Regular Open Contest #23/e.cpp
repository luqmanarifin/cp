#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long minL = (n+n%2)*(m+m%2) - n*m;
  if (3*minL > n*m) {
    cout << -1 << endl;
  } else {
    cout << (n*m - 3*minL) / 4 << endl;
  }

  return 0;
}
