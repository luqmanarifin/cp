#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  bool as = 1, bs = 1;
  for(int i = 1; i < n; i++) {
    if(a[i] != a[i - 1]) as = 0;
    if(b[i] != b[i - 1]) bs = 0;
  }
  if(as || bs) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
