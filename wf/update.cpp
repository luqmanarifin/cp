#include <bits/stdc++.h>

using namespace std;

string str;

bool is_user(string str) {
  return str.back() == ']' && str.substr(0, 6) == "[user:";
}

string convert(string str) {
  return str.substr(0, str.size() - 12) + "]";
}

int main() {
  int num = 0;
  while (getline(cin, str)) {
    stringstream ss(str);
    string token, ret;
    while (ss >> token) {
      if (!ret.empty()) {
        ret += " ";
      }
      if (is_user(token)) {
        ret += convert(token);
      } else {
        ret += token;
      }
    }
    cout << ret << endl;
  }
  return 0;
}
