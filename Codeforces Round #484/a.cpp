#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  bool adjacent = 1, can = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == '1' && s[i-1] == '1') {
      adjacent = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') continue;
    bool satu = 0;
    if (i - 1 >= 0) {
      satu |= (s[i - 1] == '1');
    }
    if (i + 1 < n) {
      satu |= (s[i + 1] == '1');
    }
    if (!satu) {
      can = 1;
    }
  }
  puts(adjacent && !can? "Yes" : "No");

  return 0;
}
