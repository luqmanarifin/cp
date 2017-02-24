#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  cout << a << ' ' << b << endl;
  while (n--) {
    string c, d;
    cin >> c >> d;
    if (a == c) {
      a = d;
    } else if (b == c) {
      b = d;
    } else if (a == d) {
      a = c;
    } else if (b == d) {
      b = c;
    }
    cout << a << ' ' << b << endl;
  }
  return 0;
}
