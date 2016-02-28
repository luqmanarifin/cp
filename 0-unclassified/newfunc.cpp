#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool done[1 << 22];
set<int> bef, now;

int main() {
  int n;
  scanf("%d", &n);
  bef.insert(0);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    now.clear();
    for(auto it : bef) {
      now.insert(it | a);
      done[it | a] = 1;
    }
    now.insert(a);
    done[a] = 1;
    bef = now;
  }
  int ans = 0;
  for(int i = 0; i < (1 << 20); i++) {
    ans += done[i];
  }
  cout << ans << endl;
  return 0;
}