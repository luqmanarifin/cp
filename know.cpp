#include <bits/stdc++.h>

using namespace std;

int main() {
  bool ada = 0;
  string s;
  cin >> s;
  int pos = -1;
  int n = s.length();
  for(int i = 0; i < n - 1; i++) {
    if((s[i] - '0') % 2 == 0) {
      ada = 1;
      if(s[i] < s[n - 1]) {
        swap(s[i], s[n - 1]);
        cout << s << endl;
        return 0;
      }
      swap(s[i], s[n - 1]);
      pos = i;
      swap(s[i], s[n - 1]);
    }
  }
  if(ada) {
    swap(s[pos], s[n - 1]);
    cout << s << endl;
  }
  else puts("-1");
  return 0;
}