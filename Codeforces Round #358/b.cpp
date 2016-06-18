#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int p = 0;
  for(int i = 1; ; i++) {
    while(a[p] < i && p < n) p++;
    if(p >= n) {
      printf("%d\n", i);
      return 0;
    }
    p++;
  }
  return 0;
}
