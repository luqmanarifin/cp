#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  string ret;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '_') {
      ret += (s[i + 1] - 'a' + 'A');
      i++;
    } else if ('A' <= s[i] && s[i] <= 'Z') {
      ret += '_';
      ret += (s[i] - 'A' + 'a'); 
    } else {
      ret += s[i];
    }
  }
  cout << ret << endl;
  return 0;
}