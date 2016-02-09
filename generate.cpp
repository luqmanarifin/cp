#include <bits/stdc++.h>

using namespace std;

int n, m, n2, m2;
char s[1005][1005];

int main() {
  n = 1000;
  m = 1000;
  n2 = 1;
  m2 = 10001;
  cout << n << ' ' << m << endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      s[i][j] = rand() % 26 + 'a';
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  cout << n2 << ' ' << m2 << endl;
  bool match = 0;
  int tx = 156;
  int ty = 345;
  for(int i = 0; i < n2; i++) {
    for(int j = 0; j < m2; j++) {
      printf("%c", (match? s[tx + i][ty + j] : rand() % 26 + 'a'));
    }
    printf("\n");
  }
  return 0;
}
