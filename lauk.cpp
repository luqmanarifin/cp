#include <bits/stdc++.h>

using namespace std;

map<string, int> num;

vector<string> parse(string s) {
  vector<string> ret;
  for(int i = 0; i < s.size(); ) {
    while(s[i] == ' ' && i < s.size()) i++;
    int j = i;
    while(s[j] != '+' && j < s.size()) j++;
    int to = j + 1;
    j--;
    while(s[j] == ' ' && j > i) j--;
    ret.push_back(s.substr(i, j - i + 1));
    i = to;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  string buf;
  getline(cin, buf);
  string now = buf;
  while(buf[0] != '!') {
    if(buf[0] == '#') {
      int i = 1;
      while(buf[i] == ' ') i++;
      now = buf.substr(i);
    } else {
      num[now]++;
    }
    getline(cin, buf);
  }
  while(getline(cin, buf)) {
    long long ans = 1;
    vector<string> ret = parse(buf);
    for(auto it : ret) {
      ans *= num[it];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
