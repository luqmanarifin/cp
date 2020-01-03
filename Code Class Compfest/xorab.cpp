#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull a, b;

int ans[100];

int main() {
  cin >> a >> b;
  for (int i = 1; i < 64; i++) {
    ull bit = ((-1LL) ^ ((1LL << i) - 1));
    ull abit = (bit & a);
    ull bbit = (bit & b);
    if (abit == bbit && (a & (1LL << i))) {
      if ((b - a) % 2 == 0) {
        ans[i] = 1;
      }
    } else {
      if (a & (1LL << i)) {
        if (a % 2) {
          ans[i] ^= 1;
        }
      }
      if (b & (1LL << i)) {
        if (b % 2 == 0) {
          ans[i] ^= 1;
        }
      }
    }
  }
  if (a % 2) {
    ull ada = (b - a) / 2 + 1;
    if (ada % 2) {
      ans[0] = 1;
    }
  } else {
    ull ada = (b - a + 1) / 2;
    if (ada % 2) {
      ans[0] = 1;
    }
  }
  bool print = 0;
  for (int i = 63; i >= 0; i--) {
    if (ans[i]) print = 1;
    if (print) {
      printf("%d", ans[i]);
    }
  }
  if (!print) {
    printf("0");
  }
  printf("\n");

  return 0;
}
