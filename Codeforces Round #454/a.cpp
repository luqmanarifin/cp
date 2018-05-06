
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
set<char> can;
set<char> bef;

int main() {
  
  for (int i = 0; i < 26; i++) can.insert(i + 'a');
  
  int q;
  scanf("%d", &q);
  bool unique = 0;
  int ans = 0;
  for (int qq = 0; qq < q; qq++) {
    char c;
    scanf(" %c", &c);
    if (c == '!') {
      if (unique) ans++;
      
      scanf(" %s", s);
      int len = strlen(s);
      bef.clear();
      for (int i = 0; i < len; i++) {
        if (can.count(s[i])) {
          bef.insert(s[i]);
        }
      }
      can.clear();
      for (auto it : bef) can.insert(it);
      
    } else if (c == '.') {
      scanf(" %s", s);
      int len = strlen(s);
      for (int i = 0; i < len; i++) {
        can.erase(s[i]);
      }
      
    } else {
      char p;
      scanf(" %c", &p);
      
      if (unique && p != *(can.begin())) {
        ans++;
      }
      if (can.size() > 1) {
        can.erase(p);
      }
    }
    if (can.size() == 1) unique = 1;
  }
  assert(can.size() != 0);
  cout << ans << endl;
  return 0;
}
