
#include <bits/stdc++.h>

using namespace std;

string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

string s;

int main() {
  cin >> s;
  int cnt = 0;
  for (int t = 0; t < 5; t++) {
    for (int i = 0; i + a[t].size() <= s.size(); i++) {
      if (a[t] == s.substr(i, a[t].size())) {
        cnt++;
      }
    }
  }
  puts(cnt == 1? "YES" : "NO");
  return 0;
}
