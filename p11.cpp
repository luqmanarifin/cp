#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n / 2; i++) {
    char be = min(s[i], s[n - 1 - i]);
    s[i] = s[n - 1 - i] = be;
  }
  printf("%s\n", s);
  return 0;
}
