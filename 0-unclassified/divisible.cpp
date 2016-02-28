#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    s[i] -= '0';
  }
  for(int i = 0; i < n; i++) {
    if(s[i] % 8 == 0) {
      puts("YES");
      printf("%d\n", s[i]);
      return 0;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if((s[i] * 10 + s[j]) % 8 == 0) {
        puts("YES");
        printf("%d%d\n", s[i], s[j]);
        return 0;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if((s[i] * 100 + s[j] * 10 + s[k]) % 8 == 0) {
          puts("YES");
          printf("%d%d%d\n", s[i], s[j], s[k]);
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
