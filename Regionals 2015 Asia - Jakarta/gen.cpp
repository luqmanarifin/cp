#include <bits/stdc++.h>

using namespace std;

int cnt[5];

int main() {
  int pol = 1;
  for (int i = 0; i < 5; i++) pol *= 3;
  for (int mask = 0; mask < pol; mask++) {
    int n = 0;
    int tmp = mask;
    for (int i = 0; i < 5; i++) {
      cnt[i] = tmp % 3;
      n += cnt[i];
      tmp /= 3;
    }
    for (int a = 1; a <= n; a++) {
      printf("%d %d %d\n", n, a, a);
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          printf("%d ", i - 2);
        }
      }
      printf("\n");
    }
  }

  return 0;
}
