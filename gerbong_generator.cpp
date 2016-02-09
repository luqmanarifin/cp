#include <bits/stdc++.h>

using namespace std;

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  for(int i = 144; i <= 225; i++) {
    int num = get(5, 12);
    for(int j = 0; j < num; j++) {
      cout << "(\"" << i << "\", \"" << get(30, 70) << "\", \"";
      int m = get(1, 12);
      int d = get(1, 28);
      printf("%4d-%d%d-%d%d\"),\n", get(1999, 2014), m / 10, m % 10, d / 10, d % 10);
    }
  }
  return 0;
}
