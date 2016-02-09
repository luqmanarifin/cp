#include <bits/stdc++.h>

using namespace std;

char s[105];
char code[] = "CODEFORCES";

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int awal = 0, akhir = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == code[i]) {
      awal++;
    } else {
      break;
    }
  }
  int cn = strlen(code);
  for(int i = 0; i < n; i++) {
    if(s[n - 1 - i] == code[cn - 1 - i]) {
      akhir++;
    } else {
      break;
    }
  }
  if(awal + akhir >= cn) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
