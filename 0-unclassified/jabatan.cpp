#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string s) {
  stringstream ss(s);
  string buf;
  vector<string> ret;
  int cnt = 0;
  while(ss >> buf) {
    ret.push_back(buf);
  }
  return ret;
}

string combine(vector<string> s) {
  string ret;
  for(auto it : s) {
    ret += it + " ";
  }
  return ret;
}

string buffer;

int main() {
  while(getline(cin, buffer)) {
    vector<string> v = parse(buffer);
    vector<string> now;
    for(int i = 3; i < v.size(); i++) {
      now.push_back(v[i]);
    }
    string name = combine(now);
    cout << name << endl;
  }
  return 0;
}
