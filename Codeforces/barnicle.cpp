#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n;
char s[N];
int b;

bool isZero(int i) {
  bool yes = 1;
  for (; i < N; i++) if (s[i]) yes = 0;
  return yes;
}

int main() {
  scanf("%d.%s", &n, s);
  //printf("%d %s %d\n", n, s, b);
  int len = strlen(s);
  int p = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'e') {
      p = i;
    }
  }
  b = atoi(s + p + 1);
  for (int i = 0; i < p; i++) {
    s[i] -= '0';
  }
  for (int i = p; i < len; i++) s[i] = 0;

  bool allZero = 1;
  if (n) allZero = 0;
  for (int i = 0; i < b; i++) if (s[i]) allZero = 0;
  if (allZero) printf("0");
  else {
    printf("%d", n);
    for (int i = 0; i < b; i++) printf("%d", s[i]);
  }
  if (!isZero(b)) {
    printf(".");
    int last = 0;
    for (int i = 0; i < N; i++) {
      if (s[i]) {
        last = i;
      }
    }
    for (int i = b; i <= last; i++) printf("%d", s[i]);
  }

  return 0;
}
