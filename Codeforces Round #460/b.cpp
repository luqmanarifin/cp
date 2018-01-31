#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int len;
int a[N], pt, k;

void dfs(int pos, int sum) {
  if (pos == len - 1) {
    pt++;
    a[pos] = 10 - sum;
    if (pt == k) {
      for (int i = 0; i < len; i++) printf("%d", a[i]); printf("\n");
      exit(0);
    }
    return;
  }
  for (int i = 0; i <= min(9, 10 - sum); i++) {
    a[pos] = i;
    dfs(pos + 1, sum + i);
  }
}

int main() {
  scanf("%d", &k);
  for (len = 2; ; len++) {
    for (int i = 1; i <= 9; i++) {
      a[0] = i;
      dfs(1, i);
    }
  }
  
  return 0;
}
