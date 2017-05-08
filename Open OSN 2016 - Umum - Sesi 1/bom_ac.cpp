#include <bits/stdc++.h>

using namespace std;

char s[10];
int n;
int first = -1, second = -1, bip;

void solve() {
  int d = second - first;
  int ke = d / 2 + 1;
  int lim = n - n/2 + n - ke, at;
  //printf("ke lim %d %d\n", ke, lim);
  if (first < lim) {
    at = n + 1 - ke;
  } else {
    at = ke;
  }
  while (bip < n) {
    printf("%d\n", at);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B') bip++;
  }
}

int main() {
  int t, type;
  scanf("%s %d %d %d", s, &n, &t, &type);
  
  int p = 0;
  for (int i = n/2+1; i <= n; i++) {
    printf("%d\n", i);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B') {
      if (first == -1) first = p;
      else if (second == -1) second = p;
      bip++;
    }
    if (bip == 2) {
      solve();
      return 0;
    }
    p++;
  }
  for (int i = n; i >= 1; i--) {
    printf("%d\n", i);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B') {
      if (first == -1) first = p;
      else if (second == -1) second = p;
      bip++;
    }
    if (bip == 2) {
      solve();
      return 0;
    }
    p++;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", i);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B') {
      if (first == -1) first = p;
      else if (second == -1) second = p;
      bip++;
    }
    if (bip == 2) {
      solve();
      return 0;
    }
    p++;
  }
  for (int i = n; i >= n/2+1; i--) {
    printf("%d\n", i);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B') {
      if (first == -1) first = p;
      else if (second == -1) second = p;
      bip++;
    }
    if (bip == 2) {
      solve();
      return 0;
    }
    p++;
  }
  return 0;
}