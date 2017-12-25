#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    
    int n;
    cin >> n;
    while (n--) {
      string str;
      cin >> str;
      mp[str]++;
    }
    
    int best = -1, ada = 0;
    string ans;
    for (auto it : mp) {
      if (it.second > best) {
        best = it.second;
        ada = 1;
        ans = it.first;
      } else if (it.second == best) {
        ada++;
      }
    }
    if (ada == 1) {
      printf("%s\n", ans.c_str());
    } else {
      puts("Draw");
    }
  }

  return 0;
}
