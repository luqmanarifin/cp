#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int i = 1; i < 50; i++) printf("%d %d\n", i, __builtin_clz(i) ^ 31);

  return 0;
}
