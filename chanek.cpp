#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    string s, a, b;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
      if('a' <= s[i] && s[i] <= 'z') {
        a.push_back(s[i]);
      } else {
        b.push_back(s[i]);
      }
    }
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    puts(a == b? "SEHAT" : "TIDAK SEHAT");
  }
  
  return 0;
}
