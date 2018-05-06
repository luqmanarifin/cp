
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s[0] - '0';
  int b = s[2] - '0';
  if (s[1] == '+') {
    cout << a + b << endl;
  } else {
    cout << a - b << endl;
  }
  return 0;
}
