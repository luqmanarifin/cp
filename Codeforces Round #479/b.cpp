#include <bits/stdc++.h>

using namespace std;

string s;
map<string, int> mp;

int main() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i + 2 <= s.size(); i++) {
    mp[s.substr(i, 2)]++;
  }
  int ans = -1; string niki;
  for (auto it : mp) {
    if (it.second > ans) {
      ans = it.second;
      niki = it.first;
    }
  }
  cout << niki << endl;
  return 0;
}
