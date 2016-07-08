#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 15;
  printf("%d\n", t);
  while(t--) {
    int n = 600;
    printf("%d\n", n);
    for(int i = 0; i < n; i++) printf("%c", rand() % 26 + 'a'); printf("\n");
    for(int i = 0; i < n; i++) printf("%c", rand() % 26 + 'a'); printf("\n");
  }

  return 0;
}
