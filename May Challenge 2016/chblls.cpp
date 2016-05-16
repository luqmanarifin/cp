#include <bits/stdc++.h>

using namespace std;

int main() {
  puts("1");
  puts("3 1 2 2");
  puts("3 3 4 4");
  fflush(stdout);
  int n;
  scanf("%d", &n);
  puts("2");
  if(n == 1) {
    puts("1");
  } else if(n == 2) {
    puts("2");
  } else if(n == -1) {
    puts("3");
  } else if(n == -2) {
    puts("4");
  } else {
    puts("5");
  }
  fflush(stdout);
  return 0;
}