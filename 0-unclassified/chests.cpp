#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int m;
  scanf("%d", &m);
  while(m--) {
    int val;
    scanf("%d", &val);
    printf("%d\n", lower_bound(a, a + n, val) - a + 1);
  }
  
  return 0;
}
