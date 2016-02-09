#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  int beda = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      beda++;
    }
  }
  if(beda % 2) {
    puts("impossible");
    return 0;
  }
  int now = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i]) {
      printf("%c", a[i]);
    } else {
      if(now < beda / 2) {
        printf("%c", a[i]);
        now++;
      } else {
        printf("%c", b[i]);
      }
    }
  }
  
  return 0;
}
