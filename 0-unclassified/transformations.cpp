#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int q;
  scanf("%d", &q);
  while(q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int to = (a + b) >> 1;
    for(int i = 0; a + i <= to; i++) {
      swap(s[a + i], s[b - i]);
    }
    printf("%s\n", s);
  }
  
  return 0;
}
