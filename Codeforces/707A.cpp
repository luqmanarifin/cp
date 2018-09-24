#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool grey = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      scanf(" %c", &c);
      if (c != 'W' && c != 'B' && c != 'G') {
        grey = 0;
      }
    }
  }
  puts(grey? "#Black&White" : "#Color");
  return 0;
}
