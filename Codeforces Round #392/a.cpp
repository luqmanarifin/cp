#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int main() {
  int n, sum = 0, maks = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    maks = max(maks, v);
    sum += v;
  }
  printf("%d\n", maks * n - sum);
  return 0;
}
