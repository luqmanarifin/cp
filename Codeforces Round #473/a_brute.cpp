
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int is[N][2];

int find(int now, int s) {
  if (now == 0) return 0;
  if (is[now][s] != -1) return is[now][s];
  if (s == 0) {
    for (int i = 2; i <= now; i += 2) {
      if (find(now - i, s ^ 1) == 0) {
        return is[now][s] = 1;
      }
    }
  } else {
    for (int i = 1; i <= now; i += 2) {
      if (find(now - i, s ^ 1) == 0) {
        return is[now][s] = 1;
      }
    }
  }
  return is[now][s] = 0;
}

int main() {
  memset(is, -1, sizeof(is));
  for (int i = 1; i < N; i++) {
    printf("%d %d\n", i, find(i, 0));
  }

  return 0;
}
