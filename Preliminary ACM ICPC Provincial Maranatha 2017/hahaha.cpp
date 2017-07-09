#include <bits/stdc++.h>

using namespace std;


bool is(char c) {
  return 'a' <= c && c <= 'z';
}

bool haha(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      if (s[i] != 'h') return 0;
    } else {
      if (s[i] != 'a') return 0;
    }
  }
  return s.size() % 2 == 0;
}

string convert(int n) {
  string ret = "";
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ret += "w";
    } else {
      ret += "k";
    }
  }
  return ret;
}

string s;

int main() {
  getline(cin, s);
  stringstream ss(s);
  string buf;
  vector<string> ans;
  while (ss >> buf) {
    if (haha(buf)) {
      ans.push_back(convert(buf.length()));
    } else {
      ans.push_back(buf);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%s", ans[i].c_str());
  }
  printf("\n");
  return 0;
}
