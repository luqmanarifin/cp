#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int f;
  scanf("%s %d", s, &f);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    s[i] -= 'A';
    s[i] = (s[i] - f + 26) % 26;
    printf("%c", s[i] + 'A');
  }
  printf("\n");
  return 0;
}
