#include <bits/stdc++.h>

using namespace std;

const int N = 606;

int a[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  vector<int> ans;
  int num = 0;
  for(int i = 1; i <= n; i++) {
    num += a[i][i];
  }
  int now = 0;
  for(int i = 1; i <= n; i++) {
    now += a[n - i + 1][i];
  }
  if(now != num) {
    ans.push_back(0);
  }
  for(int i = 1; i <= n; i++) {
    now = 0;
    for(int j = 1; j <= n; j++) {
      now += a[i][j];
    }
    if(now != num) {
      ans.push_back(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    now = 0;
    for(int j = 1; j <= n; j++) {
      now += a[j][i];
    }
    if(now != num) {
      ans.push_back(-i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto it : ans) {
    printf("%d\n", it);
  }
  
  return 0;
}
