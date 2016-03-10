#include <bits/stdc++.h>

using namespace std;

char s[20];

void lompat(int l, int r) {
  int cnt = (r - l) / 2 + 1;
  if(cnt == 1) {
    printf("0 %d\n", l);
    fflush(stdout);
    return;
  }
  if(cnt == 2) {
    printf("1 %d\n", l);
    fflush(stdout);
    scanf("%s", s);
    if(s[0] == 'Y') {
      printf("0 %d\n", l);
      fflush(stdout);
    } else {
      printf("0 %d\n", l + 2);
      fflush(stdout);
    }
    return;
  }
  int p = (cnt + 1) / 3;
  printf("%d", 2 * p);
  for(int i = 0; i < p; i++) {
    printf(" %d", l + i*2 - 1);
  }
  for(int i = 0; i < p; i++) {
    printf(" %d", l + p * 2 + i * 2);
  }
  printf("\n");
  fflush(stdout);
  scanf("%s", s);
  if(s[0] == 'Y') {
    lompat(l + 2 * p, l + 4 * p - 1);
  } else if(s[0] == 'B') {
    lompat(l, l + 2 * p - 1);
  } else {
    lompat(l + 4 * p, r);
  }
}

void linear(int l, int r) {
  int cnt = r - l + 1;
  if(cnt == 1) {
    printf("0 %d\n", l);
    fflush(stdout);
    return;
  }
  if(cnt == 2) {
    printf("1 %d\n", l);
    fflush(stdout);
    scanf("%s", s);
    if(s[0] == 'Y') {
      printf("0 %d\n", l);
      fflush(stdout);
    } else {
      printf("0 %d\n", r);
      fflush(stdout);
    }
    return;
  }
  int p = (cnt + 1) / 3;
  printf("%d", p);
  for(int i = 0; i < p; i++) {
    printf(" %d", l + i * 2);
  }
  printf("\n");
  fflush(stdout);
  scanf("%s", s);
  if(s[0] == 'Y') {
    lompat(l, l + (p - 1) * 2);
  } else if(s[0] == 'B') {
    lompat(l + 1, l + (p - 1) * 2 + 1);
  } else {
    linear(l + 2 * p, r);
  }
}

int main() {
  scanf("%s", s);
  int n, k;
  scanf("%d %d", &n, &k);
  linear(1, n);
  return 0;
}
