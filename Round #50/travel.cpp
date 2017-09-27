#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') {
      a++;
    } else if (s[i] == 'S') {
      a--;
    } else if (s[i] == 'E') {
      b++;
    } else {
      b--;
    }
  }
  cout << abs(a) + abs(b) << endl;
  return 0;
}
