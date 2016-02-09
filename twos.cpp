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
    }
    if(s[i] == 'B' && s[i + 1] == 'A') {
      b.push_back(i);
    }
  }
  for(auto i : a) {
    for(auto j : b) {
      if(abs(i - j) > 1) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
