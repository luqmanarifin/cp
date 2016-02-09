#include <bits/stdc++.h>

using namespace std;

int na[3], nb[3];
int ans[3];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < 3; i++) {
    scanf("%d %d", na + i, nb + i);
    ans[i] = na[i];
    n -= na[i];
  }
  for(int i = 0; i < 3; i++) {
    int low = nb[i] - ans[i];
    int ent = min(low, n);
    n -= ent;
    ans[i] += ent;
  }
  for(int i = 0; i < 3; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
