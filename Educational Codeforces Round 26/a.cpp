#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  int ans = 0;
  while (cin >> s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
      if ('A' <= s[i] && s[i] <= 'Z') {
        cur++;
      }
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
