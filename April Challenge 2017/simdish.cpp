#include <bits/stdc++.h>

using namespace std;

string s[5];

int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; i++) {
      cin >> s[i];
    }
    set<string> ada;
    for (int i = 0; i < 4; i++) {
      string str;
      cin >> str;
      ada.insert(str);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      if (ada.count(s[i])) {
        ans++;
      }
    }
    puts(ans >= 2? "similar" : "dissimilar");
  }

  return 0;
}
