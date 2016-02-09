#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int h[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", h + i);
  }
  int mx = -1;
  for(int i = n - 1; i >= 0; i--) {
    ans[i] = max(0, mx - h[i] + 1);
    mx = max(mx, h[i]);
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  
  return 0;
}
