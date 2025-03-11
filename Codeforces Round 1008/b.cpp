#include <bits/stdc++.h>

using namespace std;

void ask(int x) {
  printf("%d\n", x);
  fflush(stdout);
}

void answer() {
  printf("!\n");
  fflush(stdout);
}

int get() {
  int x;
  scanf("%d", &x);
  return x;
}

int main() {
  int magic_a = 0;
  int magic_b = 0;
  for (int i = 0; i < 30; i++) {
    if (i % 2 == 0) {
      magic_b |= (1 << i);
    } else {
      magic_a |= (1 << i);
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    ask(magic_a);
    int ans_a = get();
    ask(magic_b);
    int ans_b = get();

    vector<int> ans(30);
    for (int i = 0; i < 30; i++) {
      if (i % 2 == 0) {
        int here = (ans_a & ((1 << i) | (1 << (i + 1))));
        ans[i] = (here >> i);
        ans_a -= here;
      } else {
        ans_a -= 2 * (1 << i);
      }
    }
    for (int i = 0; i < 30; i++) {
      if (i % 2 == 1) {
        int here = (ans_b & ((1 << i) | (1 << (i + 1))));
        ans[i] = (here >> i);
        ans_b -= here;
      } else {
        ans_b -= 2 * (1 << i);
      }
    }
    answer();
    int m = get();
    int res = 0;
    for (int i = 0; i < 30; i++) {
      if (m & (1 << i)) {
        res += 2 * (1 << i);
      } else {
        res += ans[i] * (1 << i);
      }
    }
    printf("%d\n", res);
  }

  return 0;
}
