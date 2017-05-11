#include <bits/stdc++.h>

using namespace std;

void analyze(string a) {
  int sum = 0;
  for (int i = 0; i < a.length(); i++) {
    if (i) printf("+");
    printf("%c", a[i]);
  }
  printf("\n");
  for (int i = 0; i < a.length(); i++) {
    int c = a[i] - 'A' + 1;
    sum += c;
    if (i) printf("+");
    printf("%d", c);
  }
  printf(" = %d\n", sum);
}

int main() {
  analyze("LAZINESS");
  analyze("PROCRASTINATION");
  return 0;
}