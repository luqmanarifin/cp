#include <bits/stdc++.h>

using namespace std;

int a[105], b[105];
vector<int> t[1005];
bool done[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    t[a[i]].push_back(i);
  }
  for(int i = 0; i < n; i++) {
    for(auto it : t[b[i]]) {
      if(it == i) continue;
      done[it] = 1;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(!done[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
