#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int sum = 0, up = 0, down = 0;
    for(int i = 0; i < n; i++) {
      s[i] -= '0';
      sum += s[i];
      up += 9 - s[i];
      if(i != 0 || n == 1) down += s[i];
    }
    int u = 9 - sum % 9;
    int d = sum % 9;
    if(up >= u && down >= d) {
      printf("%d\n", min(u, d));
    } else if(up >= u) {
      printf("%d\n", u);
    } else {
      printf("%d\n", d);
    }
  }
  
  return 0;
}
