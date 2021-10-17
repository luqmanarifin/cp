#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int MAX = 20005;

bool is[MAX];
int a[N];

void print(int n, int except) {
  bool first = 1;
  for (int i = 1; i <= n; i++) {
    if (i == except) continue;
    if (!first) printf(" ");
    first = 0;
    printf("%d", i);
  }
  printf("\n");
}

int main() {
  for (int i = 2; i < MAX; i++) {
    if (!is[i]) {
      for (int j = 2 * i; j < MAX; j += i) {
        is[j] = 1;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    if (is[sum]) {
      printf("%d\n", n);
      print(n, 0);
    } else {
      for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
          printf("%d\n", n - 1);
          print(n, i);
          break;
        }
      }
    }
  }

  return 0;
}
