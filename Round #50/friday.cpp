#include <bits/stdc++.h>

using namespace std;

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
string str[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
  string s;
  cin >> s;
  int d = -1;
  for (int i = 0; i < 7; i++) {
    if (str[i] == s) {
      d = i;
      break;
    }
  }
  int ans = 0;
  for (int i = 0; i < 12; i++) {
    int cur = (d + 12) % 7;
    if (cur == 4) ans++;
    d = (d + days[i]) % 7;
  }
  cout << ans << endl;
  return 0;
}
