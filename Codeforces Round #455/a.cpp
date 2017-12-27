#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  string ans = a + b[0];
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      string cur = a.substr(0, i) + b.substr(0, j);
      if (cur < ans) ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
