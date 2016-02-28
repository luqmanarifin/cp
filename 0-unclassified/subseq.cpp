#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
char maks[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = n - 1; i >= 0; i--) {
    maks[i] = max(maks[i + 1], s[i]);
  }
  for(int i = 0; i < n; i++) {
    if(s[i] == maks[i]) {
      printf("%c", s[i]);
    }
  }
  printf("\n");
  return 0;
}