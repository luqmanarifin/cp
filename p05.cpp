#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
  cin >> str;
  int n = str.length();
  bool found = 0;
  for(int len = n / 2; len >= 1 && !found; len--) {
    for(int i = 0; i < n && !found; i++) {
      for(int j = i + len; j + len <= n && !found; j++) {
        if(str.substr(i, len) == str.substr(j, len)) {
          found = 1;
          printf("%d\n", len);
        }
      }
    }
  }
  if(!found) puts("0");
  return 0;
}
