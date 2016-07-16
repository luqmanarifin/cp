#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  printf("%s", s);
  reverse(s, s + n);
  printf("%s\n", s);
  return 0;
}
