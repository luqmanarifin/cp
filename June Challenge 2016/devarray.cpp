#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int mini = 1e9, maks = -1e9;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    mini = min(mini, num);
    maks = max(maks, num);
  }
  while(q--) {
    int num;
    scanf("%d", &num);
    puts(mini <= num && num <= maks? "Yes" : "No");
  }
  return 0;
}