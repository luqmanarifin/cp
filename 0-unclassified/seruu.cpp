#include <bits/stdc++.h>

using namespace std;

const int N = 205;

string ans;
string buf;

int count_small(string str) {
  int cnt = 0;
  for(int i = 0; i < str.length(); i++) {
    if('a' <= str[i] && str[i] <= 'z') {
      cnt++;
    }
  }
  return cnt;
}

int ada(string str) {
  for(int i = 0; i < str.length(); i++) {
    if('0' <= str[i] && str[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

int main() {
  getline(cin, buf);
  stringstream ss(buf.c_str());
  while(ss >> buf) {
    int len = buf.size();
    if(buf[len - 1] == '.') {
      buf = buf.substr(0, len - 1);
    }
    if(count_small(buf) >= 3 && ada(buf)) {
      if(buf.size() > ans.size()) {
        ans = buf;
      }
    }
  }
  if(ans.size() > 0) {
    printf("%s\n%d\n", ans.c_str(), ans.length());
  } else {
    puts("NO");
  }
  return 0;
}
