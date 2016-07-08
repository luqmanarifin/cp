#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];
bool done[N][N];
bool td[N][N];

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {
  if(!valid(i, j) || done[i][j] || s[i][j] == '#') return;
  done[i][j] = 1;
  for(int k = 0; k < 4; k++) {
    dfs(i + da[k], j + db[k]);
  }
}

void find(int i, int j) {
  if(!valid(i, j) || td[i][j] || s[i][j] == '#') return;
  td[i][j] = 1;
  for(int k = 0; k < 4; k++) {
    find(i + da[k], j + db[k]);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%s", s[i]);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        dfs(i, j);
        goto YO;
      }
    }
  }
  YO:;
  int si, sj;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.' && !done[i][j]) {
        puts("Impossible");
        return 0;
      }
      if(s[i][j] == '.') {
        si = i;
        sj = j;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '?' && done[i][j]) {
        memset(td, 0, sizeof(td));
        s[i][j] = '#';
        find(si, sj);
        s[i][j] = '?';
        
        bool all = 1;
        for(int k = 0; k < n; k++) {
          for(int l = 0; l < m; l++) {
            if(s[k][l] == '.' && !td[k][l]) {
              all = 0;
            }
          }
        }
        if(all) {
          puts("Ambiguous");
          return 0;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '?') {
        if(done[i][j]) {
          printf(".");
        } else {
          printf("#");
        }
      } else {
        printf("%c", s[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
