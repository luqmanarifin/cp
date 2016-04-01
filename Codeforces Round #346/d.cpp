#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  vector<int> dir;
  for(int i = 0; i < n; i++) {
    if(a[i] == a[i + 1]) {
      if(b[i] < b[i + 1]) {
        dir.push_back(0);
      } else {
        dir.push_back(2);
      }
    } else {
      if(a[i] < a[i + 1]) {
        dir.push_back(1);
      } else {
        dir.push_back(3);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < dir.size(); i++) {
    int j = (i + 1) % dir.size();
    if((dir[j] + 1) % 4 == dir[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
