#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    if (s[0] != s[n - 1]) {
      s[n - 1] = s[0];
    }
    printf("%s\n", s);
  }

  return 0;
}
