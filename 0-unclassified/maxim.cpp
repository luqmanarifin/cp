#include <bits/stdc++.h>

using namespace std;

long long num[15][15];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    num[1][i] = 1;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      num[i][j] = num[i][j - 1] + num[i - 1][j];
    }
  }
  cout << num[n][n] << endl;
  return 0;
}