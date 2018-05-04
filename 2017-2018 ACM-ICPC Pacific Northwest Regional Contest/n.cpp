#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  bool odd = 1;
  int n = s.size();
  for (int len = 1; len <= n; len++) {
    for (int st = 0; st + len <= n; st++) {
      bool palin = 1;
      for (int i = 0; i < len; i++) {
        if (s[st + i] != s[st + len - 1 - i]) {
          palin = 0;
        }
      }
      if (palin && len % 2 == 0) {
        odd = 0;
      }
    }
  }
  puts(odd? "Odd." : "Or not.");

  return 0;
}
