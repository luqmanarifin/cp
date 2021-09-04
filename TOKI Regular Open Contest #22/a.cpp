#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
