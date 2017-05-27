#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
int a[N];

int main() {
  int k;
  scanf("%s %d", s, &k);
  k--;
  int n = strlen(s);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '_') {
      a[i] = k % 26;
      k /= 26;
    }    
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '_') {
      printf("%c", a[i] + 'a');
    } else {
      printf("%c", s[i]);
    }
  }
  printf("\n");
  return 0;
}
