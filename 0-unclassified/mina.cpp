// too easy to AC
#include <bits/stdc++.h>

using namespace std;

char s[5];
int ans[150], p[150];

int main() {
  for(int i = 2; i <= 144; i++) {
    ans[i] = 1e9;
    for(int j = 1; j < i; j++) {
      int cur = max(ans[j] + 2, ans[i - j] + 1);
      if(cur < ans[i]) {
        ans[i] = cur;
        p[i] = j;
      }
    }
  }
  int n;
  scanf("%d", &n);
  if(n < ans[144]) {
    printf("Not enough money\n");
    fflush(stdout);
    return 0;
  }
  printf("Let's play!\n");
  fflush(stdout);
  
  int l = 1, r = 144;
  while(l < r) {
    int len = r - l + 1;
    printf("%d", p[len]);
    for(int i = 0; i < p[len]; i++) {
      printf(" %d", l + i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%s", s);
    if(s[0] == 'Y') {
      r = l + p[len] - 1;
    } else {
      l = l + p[len];
    }
  }
  printf("0 %d\n", l);
  fflush(stdout);
  return 0;
}
