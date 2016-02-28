#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N][N];
int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    int now = 0;
    for(int j = m - 1; j >= 0; j--) {
      if(s[i][j] == '1') now++;
      else now = 0;
      a[i][j] = now;
    }
  }
  int ans = 0;
  for(int j = 0; j < m; j++) {
    vector<int> top;
    for(int i = 0; i < n; i++) {
      top.push_back(a[i][j]);
    }
    sort(top.begin(), top.end());
    reverse(top.begin(), top.end());
    for(int i = 0; i < n; i++) {
      ans = max(ans, (i + 1) * top[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
