#include <bits/stdc++.h>

using namespace std;

bool done[16];
int cnt;

void dfs(int p, int l, int r) {
  cnt++;
  if(l == r) return;
  int mid = (l + r) >> 1;
  dfs(p + p, l, mid);
  dfs(p + p + 1, mid + 1, r);
}

int main() {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      done[i ^ j] = 1;
    }
  }
  for(int i = 0; i < 16; i++) printf("%d ", done[i]);
  dfs(1, 1, 100000);
  cout << cnt << endl;
  return 0;
}