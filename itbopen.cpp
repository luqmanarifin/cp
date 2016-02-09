#include <bits/stdc++.h>

using namespace std;

vector<string> str;

int main() {
  string buf;
  while(getline(cin, buf)) {
    str.push_back(buf);
  }
  sort(str.begin(), str.end());
  str.resize(distance(str.begin(), unique(str.begin(), str.end())));
  for(auto it : str) {
    cout << it << endl;
  }
  return 0;
}
