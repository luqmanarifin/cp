#include <bits/stdc++.h>

using namespace std;

const int N = 10;

char board[10][10];

int main() {
  for(int i = 0; i < 8; i++) {
    scanf("%s", board[i]);
  }
  int ans = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(i % 2 == j % 2 && board[i][j] == 'F') {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
