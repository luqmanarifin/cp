#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int a[N], b[N];

int main() {
  for (int i = 0; i < 5; i++) scanf("%d", a + i);
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d", b + i);
    int d = abs(a[i] - b[i]); 
    sum += min(d, 10 - d);
  }
  printf("%d\n", sum);
  return 0;
}
