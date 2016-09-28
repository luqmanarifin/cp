#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int p = -1;

void add(int at) {
  while (s[at] == '.' || s[at] == '9') {
    if (s[at] == '.') {
      at--;
    } else {
      s[at] = '0';
      at--;
    }
  }
  if (at == 0) {
    s[0] = '1';
  } else {
    s[at]++;
  }
}

int main() {
  int n, t;
  scanf("%d %d %s", &n, &t, s + 1);
  for (int i = 1; i <= n; i++) if (s[i] == '.') p = i;
  //printf("%d\n", p);
  for (int i = p + 1; i <= n; i++) {
    if (s[i] >= '5') {
      s[i] = 0;
      add(i - 1);
      t--;
      int j = i - 1;
      while (t--) {
        if (j == p) break;
        if (s[j] >= '5') {
          s[j] = 0;
          add(j - 1);
        } else {
          break;
        }
        j--;
      }
      break;
    }
  }
  //printf("%s", s + 1);
  //puts("COK");
  bool ada = 0;
  for (int i = p + 1; i < n + 1; i++) {
    if (s[i]) {
      
    } else {
      int til = p - 1;
      for (int j = i - 1; j > p; j--) {
        if (s[j] == '.') {
          til = j - 1;
          break;
        }
        if (s[j] > '0') {
          til = j;
          break;
        }
      }
      //printf("til %d\n", til);
      s[til + 1] = 0;
      break;
    }
  }
  if (s[0]) {
    printf("%s\n", s);
  } else {
    printf("%s\n", s + 1);
  }
  return 0;
}