#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  for(int i = 0; i < n; i++) {
    if(i == 0 && s[i] == '9') {
      printf("%c", s[i]);
      continue;
    }
    s[i] -= '0';
    if(9 - s[i] < s[i]) s[i] = 9 - s[i];
    printf("%d", s[i]);
  }
  return 0;
}