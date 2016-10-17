#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int w[N];

int main() {
  srand(time(0));
  int n = 500000;
  int c = 1000000;
  printf("%d %d\n", n, c);
  for (int i = 0; i < 1000000; i++) {
    int at = rand() % n;
    int col = rand() % c + 1;
    w[at]++;
  }
  sort(w, w + n);
  for (int i = 0; i < n; i++) {
    printf("%d", w[i]);
    for (int j = 0; j < w[i]; j++) printf(" %d", 1); printf("\n");
  }

  return 0;
}
