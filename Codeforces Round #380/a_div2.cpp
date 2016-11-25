#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
int to[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) {
    if (i + 2 < n) {
      if (s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
        int j = i + 2;
        while (j + 2 < n && s[j+1] == 'g' && s[j+2] == 'o') j += 2;
        to[i] = j;
        i = j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (to[i]) {
      printf("***");
      i = to[i];
    } else {
      printf("%c", s[i]);
    }
  }
  
  return 0;
}
