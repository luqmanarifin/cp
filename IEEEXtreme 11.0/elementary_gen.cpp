#include <bits/stdc++.h>

using namespace std;

string s = "barbasc";
string str = "jqwxz";

int main() {
  for (int i = 0; i < 26; i++) {
    printf("%s%c\n", s.c_str(), i + 'a');
  }
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < 26; j++) {
      printf("%s%c%c\n", s.c_str(), str[i], j + 'a');
    }
  }
  return 0;
}
