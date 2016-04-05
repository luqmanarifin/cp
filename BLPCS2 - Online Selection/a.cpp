#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%lld", a[i]);
  }
  printf("\n");
  return 0;
}
