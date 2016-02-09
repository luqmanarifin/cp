#include <bits/stdc++.h>

using namespace std;

vector<string> code;

int main() {
  string buffer;
  while(getline(cin, buffer)) {
    code.push_back(buffer);
  }
  sort(code.begin(), code.end());
  string bef = "";
  for(auto it : code) {
    if(it == bef) continue;
    cout << it << endl;
    bef = it;
  }
  return 0;
}
