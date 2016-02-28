#include <bits/stdc++.h>

using namespace std;

vector<string> s;

bool cmp(string a, string b) {
  if(a.length() != b.length()) {
    return a.length() < b.length();
  }
  for(int i = 0; i < a.length(); i++) {
    if(a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return 1;
}

int main() {
  for(int len = 1; len <= 9; len++) {
    for(int mask = 0; mask < (1 << len); mask++) {
      string str;
      for(int i = 0; i < len; i++) {
        if(mask & (1 << i)) {
          str.push_back('7');
        } else {
          str.push_back('4');
        }
      }
      s.push_back(str);
    }
  }
  sort(s.begin(), s.end(), cmp);
  string str;
  cin >> str;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == str) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
