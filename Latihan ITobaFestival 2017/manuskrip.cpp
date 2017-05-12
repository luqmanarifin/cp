#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &s[i][j]);
    }
  }
  string ans;
  for (int x = 0; x < n; x++) {
    int i = 0, j = x;
    while (i < n && j >= 0) {
      if ('a' <= s[i][j] && s[i][j] <= 'z') ans += s[i][j];
      i++;
      j--;
    }
  }
  for (int x = 1; x < n; x++) {
    int i = x, j = n - 1;
    while (i < n && j >= 0) {
      if ('a' <= s[i][j] && s[i][j] <= 'z') ans += s[i][j];
      i++;
      j--;
    }
  }
  cout << ans << endl;
  return 0;
}