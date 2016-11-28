#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string str = "aiueoy";
int p[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    int cur = 0;
    for (int j = 0; j < s.size(); j++) {
      for (int k = 0; k < str.size(); k++) {
        cur += s[j] == str[k];
      }
    }
    if (p[i] != cur) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
