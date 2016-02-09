#include <bits/stdc++.h>

using namespace std;

char s[2005][2005];
int cur[2005][2005];
char k[] = "<v>^";
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  stack<pair<int, int>> st;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '*') {
        continue;
      }
      if(i && s[i - 1][j] == '.') {
        cur[i][j]++;
      }
      if(i < n - 1 && s[i + 1][j] == '.') {
        cur[i][j]++;
      }
      if(j && s[i][j - 1] == '.') {
        cur[i][j]++;
      } 
      if(j < m - 1 && s[i][j + 1] == '.') {
        cur[i][j]++;
      }
      if(cur[i][j] == 1) {
        st.emplace(i, j);
      }
    }
  }
  while(!st.empty()) {
    int x, y;
    tie(x, y) = st.top();
    st.pop();
    if(cur[x][y] != 1 || s[x][y] != '.') {
      continue;
    }
    for(int i = 0; i < 4; i++) {
      if(valid(x + dx[i], y + dy[i])) {
        if(s[x + dx[i]][y + dy[i]] == '.') {
          int a = x + dx[i];
          int b = y + dy[i];
          s[x][y] = k[i];
          s[a][b] = k[i < 2? i + 2 : i - 2];
          for(int j = 0; j < 4; j++) {
            if(valid(a + dx[j], b + dy[j])) {
              cur[a + dx[j]][b + dy[j]]--;
              if(cur[a + dx[j]][b + dy[j]] == 1) {
                st.emplace(a + dx[j], b + dy[j]);
              }
            }
            if(valid(x + dx[j], y + dy[j])) {
              cur[x + dx[j]][y + dy[j]]--;
              if(cur[x + dx[j]][y + dy[j]] == 1) {
                st.emplace(x + dx[j], y + dy[j]);
              }
            }
          }
          break;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        puts("Not unique");
        return 0;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  return 0;
}