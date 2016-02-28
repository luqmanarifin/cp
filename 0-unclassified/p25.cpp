#include <bits/stdc++.h>

using namespace std;

int main() {
  set<string> s;
  int q;
  cin >> q;
  int ans = 0;
  while(q--) {
    string name, log;
    cin >> name >> log;
    if(log == "arrives") s.insert(name);
    else s.erase(name);
    ans = max(ans, (int) s.size());
  }
  cout << ans << endl;
  return 0;
}
