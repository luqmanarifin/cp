#include <bits/stdc++.h>

using namespace std;

char s[10];

bool ask(int a, int b) {
  printf("1 %d %d\n", a, b);
  fflush(stdout);
  scanf("%s", s);
  return s[0] == 'T';
}

int find(int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (ask(mid, mid + 1)) {
    find(l, mid);
  } else {
    find(mid + 1, r);
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int x = find(1, n), y = -1;
  //printf("x = %d\n", x);
  if (x > 1) {
    y = find(1, x - 1);
    if (!ask(y, x)) y = -1;
  }
  if (y == -1) {
    y = find(x + 1, n);
  }
  printf("2 %d %d\n", x, y);
  fflush(stdout);
  return 0;
}
