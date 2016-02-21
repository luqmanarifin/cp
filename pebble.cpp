#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int last = s[n - 1] - '0';
  if(n == 1 && (last == 1 || last == 2)) {
    puts("First");
  } else {
    if(last % 2) puts("Second");
    else puts("First");
  }
  return 0;
}