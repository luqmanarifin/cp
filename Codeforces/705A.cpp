#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      printf("I hate ");
    } else {
      printf("I love ");
    }
    if (i + 1 < n) {
      printf("that ");
    }
  }
  printf("it\n");
  return 0;
}
