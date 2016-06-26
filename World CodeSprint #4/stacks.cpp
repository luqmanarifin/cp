#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n[3];
int a[3][N];
set<int> s[3];

int main() {
  for(int i = 0; i < 3; i++) scanf("%d", n + i);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n[i]; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for(int i = 0; i < 3; i++) {
    int sum = 0;
    s[i].insert(0);
    for(int j = n[i] - 1; j >= 0; j--) {
      sum += a[i][j];
      s[i].insert(-sum);
    }
  }
  for(auto it : s[0]) {
    if(s[1].count(it) && s[2].count(it)) {
      cout << -it << endl;
      return 0;
    }
  }

  return 0;
}
