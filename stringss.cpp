#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
  cin >> s >> t;
  int n = s.length();
  s[n - 1]++;
  for(int i = n - 1; s[i] == 'z' + 1; i--) {
    s[i] = 'a';
    if(i) s[i - 1]++;
  }
  if(s == t) puts("No such string");
  else cout << s << endl;
  return 0;
}