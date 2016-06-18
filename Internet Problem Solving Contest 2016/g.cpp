#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    vector<int> a;
    for(int i = 0; i < n; i++) {
      if('0' <= s[i] && s[i] <= '9') {
        a.push_back(s[i] - '0');
      }
    }
    bool allZero = 1;
    for(auto it : a) if(it) allZero = 0;
    if(allZero) {
      puts("0");
    } else {
      int i = 0;
      while(a[i] == 0 && i < a.size()) i++;
      for(; i < a.size(); i++) printf("%d", a[i]);
      printf("\n");
    }
  }
  return 0;
}
