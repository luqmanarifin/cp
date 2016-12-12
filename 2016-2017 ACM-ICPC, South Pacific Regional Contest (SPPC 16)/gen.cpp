#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 300000;
  printf("%d\n", n);
  for (int i = 0; i < 60000; i++) {
    int now = i * 10000;
    for (int j = 0; j < 4; j++) {
      printf("%d ", now);
      now += 1001;
    }
  }
  return 0;
}
