#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    board[a][b] = 1;
    int aa = board[a][b] + board[a][b+1] + board[a+1][b] + board[a+1][b+1];
    int bb = board[a][b] + board[a][b-1] + board[a+1][b] + board[a+1][b-1];
    int cc = board[a][b] + board[a][b+1] + board[a-1][b] + board[a-1][b+1];
    int dd = board[a][b] + board[a][b-1] + board[a-1][b] + board[a-1][b-1];
    if(aa == 4 || bb == 4 || cc == 4 || dd == 4) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("0");
  return 0;
}