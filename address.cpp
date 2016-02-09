#include <bits/stdc++.h>

using namespace std;

const int N = 55;

string s;

int main() {
  cin >> s;
  int n = s.length();
  int now = 0;
  if(s.substr(0, 3) == "ftp") {
    cout << "ftp";
    now = 3;
  } else {
    cout << "http";
    now = 4;
  }
  cout << "://";
  for(int i = now + 1; i < n - 1; i++) {
    if(s[i] == 'r' && s[i + 1] == 'u') {
      for(int j = now; j < i; j++) {
        printf("%c", s[j]);
      }
      cout << ".ru";
      now = i + 2;
      break;
    }
  }
  if(now < n) {
    cout << "/";
    for(int i = now; i < n; i++) {
      printf("%c", s[i]);
    }
  }
  
  return 0;
}
