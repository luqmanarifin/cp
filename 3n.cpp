#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;

bitset<N> done;
int ans;

void dfs(int n) {
  if(done[n]) return;
  done[n] = 1;
  printf("%d ", n);
  ans = max(ans, n);
  if(n == 1) return;
  if(n % 2) dfs(3 * n + 1);
  else dfs(n / 2);
}

int main() {
  for(int i = 1; i <= 1e6; i++) {
    dfs(i);
  }
  cout << ans << endl;
  return 0;
}
