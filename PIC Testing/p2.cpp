#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      puts("nol");
    } else if (n > 0) {
      if (n % 2 == 0) {
        puts("genap positif");
      } else {
        puts("ganjil positif");
      }
    } else {
      if (n % 2 == 0) {
        puts("genap negatif");
      } else {
        puts("ganjil negatif");
      }
    }
  }

  return 0;
}
