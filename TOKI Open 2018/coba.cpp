#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

bool is[N];

int main() {
  for (int i = 0; i < 100; i++) printf("%d %d\n", i, 31 ^ __builtin_clz(i));
  return 0;
}
