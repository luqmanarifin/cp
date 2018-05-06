
#include <bits/stdc++.h>

using namespace std;

int main() {
  int sum = 0, n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  printf("%d\n", sum % 2);

  return 0;
}
