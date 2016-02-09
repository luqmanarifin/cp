#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int a[3];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    while(n--) {
      scanf("%s", s);
      int len = strlen(s);
      if(4 <= len && len <= 6) {
        a[len - 4]++;
      }
    }
    printf("Case #%d:", tt);
    for(int i = 0; i < 3; i++) {
      printf(" %d", a[i]);
    }
    printf("\n");
  }
  
  return 0;
}
