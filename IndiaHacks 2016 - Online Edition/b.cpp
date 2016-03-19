#include <bits/stdc++.h>

using namespace std;

const int N = 50;

vector<int> to[6];
int n, q;
long long ans;

void dfs(int p, int v) {
  if(p == n) {
    ans++;
    return;
  }
  for(auto it : to[v]) {
    dfs(p + 1, it);
  }
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < q; i++) {
    char s[3], c;
    scanf("%s %c", s, &c);
    to[c - 'a'].push_back(s[0] - 'a');
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
