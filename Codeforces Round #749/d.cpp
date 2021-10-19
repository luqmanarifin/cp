#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int lef[N], rig[N], ans[N];

int ask(int x, int val) {
  int other = (val == 1? 2 : 1);
  printf("?");
  for (int i = 1; i <= n; i++) {
    printf(" %d", i == x? val : other);
  }
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v < x? v : 0;
}

void answer() {
  printf("!");
  for (int i = 1; i <= n; i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
}

void determine(int l, int r) {
  rig[l] = r;
  lef[r] = l;
}

int num_to_right(int i) {
  int ret = 1;
  while (rig[i]) {
    i = rig[i];
    ret++;
  }
  return ret;
}

int num_to_left(int i) {
  int ret = 1;
  while (lef[i]) {
    i = lef[i];
    ret++;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = n; i >= 2; i--) {
    if (lef[i] == 0 && num_to_right(i) != n) {
      int k = ask(i, 1);
      if (k) {
        determine(k, i);
      }
    }
    if (rig[i] == 0 && num_to_left(i) != n) {
      int k = ask(i, 2);
      if (k) {
        determine(i, k);
      }
    }
  }
  int start = 1;
  while (lef[start]) start = lef[start];
  for (int i = 1; i <= n; i++) {
    ans[start] = i;
    start = rig[start];
  }
  answer();
  return 0;
}
