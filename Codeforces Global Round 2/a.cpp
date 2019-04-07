#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
vector<int> pos[N];
int l[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    pos[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    l[i] = pos[i].size();
    r[i] = 0;
    for (int j = 0; j < pos[i].size(); j++) {
      if (pos[i][j] != j) {
        l[i] = j;
        break;
      }
    }
    int len = (int) pos[i].size();
    for (int j = 0; j < pos[i].size(); j++) {
      if (pos[i][len-j-1] != n-1-j) {
        r[i] = n-1-j;
        break;
      }
    }
    // printf("%d: %d %d\n", i, l[i], r[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, i - l[a[i]]);
    ans = max(ans, r[a[i]] - i);
  }
  cout << ans << endl;
  return 0;
}
