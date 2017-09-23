#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}
