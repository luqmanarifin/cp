#include <bits/stdc++.h>

using namespace std;

const int N = 200;

bool palin(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (palin(s)) {
    puts("YES");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    s = '0' + s;
    if (palin(s)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}