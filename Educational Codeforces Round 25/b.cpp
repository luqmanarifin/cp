#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n = 10;
char s[N][N];

bool isWin() {
  for (int px = 0; px < n; px++) {
    for (int py = 0; py < n; py++) {
      bool nice = (px + 5 <= n);
      for (int i = 0; i < 5; i++) {
        if (s[px + i][py] != 'X') {
          nice = 0;
        }
      }
      if (nice) return 1;

      nice = (py + 5 <= n);
      for (int i = 0; i < 5; i++) {
        if (s[px][py + i] != 'X') {
          nice = 0;
        }
      }
      if (nice) return 1;


      nice = (px + 5 <= n && py + 5 <= n);
      for (int i = 0; i < 5; i++) {
        if (s[px + i][py + i] != 'X') {
          nice = 0;
        }
      }
      if (nice) return 1;
    }
  }
  return 0;
}

int main() {
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        s[i][j] = 'X';
        if (isWin()) {
          puts("YES");
          return 0;
        }
        s[i][j] = '.';
      }
    }
  }
  puts("NO");
  return 0;
}
