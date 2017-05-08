#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int c = i % 4;
    if (c < 2) printf("a");
    else printf("b");
  }
  return 0;
}
