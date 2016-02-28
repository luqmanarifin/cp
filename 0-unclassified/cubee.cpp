#include <bits/stdc++.h>

using namespace std;

int per[][3] = {
  {4, 0, 2},
  {4, 0, 3},
  {0, 2, 5},
  {0, 3, 5},
  {4, 1, 2},
  {4, 1, 3},
  {1, 2, 5},
  {1, 3, 5}
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    vector<string> s;
    for(int i = 0; i < 6; i++) {
      string str;
      cin >> str;
      s.push_back(str);
    }
    bool found = 0;
    for(int i = 0; i < 8; i++) {
      bool same = 1;
      for(int j = 1; j < 3; j++) {
        if(s[per[i][j]] != s[per[i][j - 1]]) {
          same = 0;
          break;
        }
      }
      if(same) found = 1;
    }
    puts(found? "YES" : "NO");
  }
  
  return 0;
}
