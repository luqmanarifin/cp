#include <bits/stdc++.h>

using namespace std;

bool ans[200][200];
bool got[55][55];
char s[55][55];
int n;

bool valid(int i, int j) {
  return 0 <= i && 0 <= j && i < n && j < n;
}

int main() {
  memset(ans, 1, sizeof(ans));
  scanf("%d", &n);
  ans[n][n] = 1;
  int pol = 2*n - 1;
  vector<pair<int, int>> pos;
  vector<pair<int, int>> occ;
  vector<pair<int, int>> safe;
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for(int j = 0; j < n; j++) {
      if(s[i][j] == 'o') {
        pos.emplace_back(i, j);
      } else if(s[i][j] == '.') {
        safe.emplace_back(i, j);
      } else {
        occ.emplace_back(i, j);
      }
    }
  }
  for(auto ip : pos) {
    for(auto is : safe) {
      ans[is.first - ip.first + n][is.second - ip.second + n] = 0;
    }
  }
  for(auto ip : pos) {
    for(int k = 1; k <= pol; k++) {
      for(int l = 1; l <= pol; l++) {
        if(ans[k][l]) {
          if(valid(ip.first + k - n, ip.second + l - n)) {
            got[ip.first + k - n][ip.second + l - n] = 1;
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < pol; j++) {
      if(s[i][j] == 'x' && !got[i][j]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for(int i = 1; i <= pol; i++) {
    for(int j = 1; j <= pol; j++) {
      if(i == n && j == n) {
        printf("o");
      } else if(ans[i][j]) {
        printf("x");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  return 0;
}
