#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  vector<int> a, b;
  for(int i = 0; i + 1 < n; i++) {
    if(s[i] == 'A' && s[i + 1] == 'B') {
      a.push_back(i);
      i++;
    }
  }
  for(int i = 0; i + 1 < n; i++) {
    if(s[i] == 'B' && s[i + 1] == 'A') {
      b.push_back(i);
      i++;
    }
  }
  if(a.size() > 3 && b.size() > 3) {
    puts("YES");
    return 0;
  }
  bool ada = 0;
  for(auto it : a) {
    for(auto jt : b) {
      if(abs(it - jt) > 1) {
        ada = 1;
      }
    }
  }
  puts(ada? "YES" : "NO");
  
  return 0;
}
