#include <bits/stdc++.h>

using namespace std;

const int MAX = 9;

int a[MAX][MAX];
bool done[MAX][MAX];
set<int> s[MAX][MAX];

int main() {
  int n;
  freopen("sudoku.txt", "r", stdin);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if(a[i][j] == 0) {
        for(int k = 1; k <= n; k++) {
          s[i][j].insert(k);
        }
      }
    }
  }
  bool found = 1;
  while(found) {
    found = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(s[i][j].size() == 1) {
          a[i][j] = *s[i][j].begin();
        }
        if(a[i][j]) {
          if(!done[i][j]) {
            found = 1;
            done[i][j] = 1;
            for(int jj = 0; jj < n; jj++) {
              s[i][jj].erase(a[i][j]);
            }
            for(int ii = 0; ii < n; ii++) {
              s[ii][j].erase(a[i][j]);
            }
            int r = i / 3;
            int c = j / 3;
            for(int ii = 0; ii < 3; ii++) {
              for(int jj = 0; jj < 3; jj++) {
                s[r + ii][c + jj].erase(a[i][j]);
              }
            }
          }
          continue;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
