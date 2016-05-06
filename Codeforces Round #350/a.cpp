#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int mini = 1e9, maks = -1e9;
  for(int i = 0; i < 7; i++) {
    int full = n / 7;
    int cur = full * 2;
    int rem = n - full * 7;
    
    int j = (i + 6) % 7;
    if(i < rem) {
      cur++;
    }
    if(j < rem) {
      cur++;
    }
    mini = min(mini, cur);
    maks = max(maks, cur);
  }
  printf("%d %d\n", mini, maks);
  return 0;
}