#include <bits/stdc++.h>

using namespace std;

const int N = 505;

bool ada[N][N];
int c[N];
vector<int> edge[N];

void dfs(int now, int col) {
  if(c[now] != -1) {
    if(c[now] != col) {
      puts("No");
      exit(0);
    }
    return;
  }
  c[now] = col;
  for(auto it : edge[now]) {
    dfs(it, col ^ 1);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if(u > v) swap(u, v);
    ada[u][v] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(!ada[i][j]) {
        //printf("%d %d\n", i, j);
        edge[i].push_back(j);
        edge[j].push_back(i);
      }
    }
  }
  memset(c, -1, sizeof(c));
  int udah = 0;
  for(int i = 1; i <= n; i++) {
    if(edge[i].size() && c[i] == -1) {
      if(udah) {
        puts("No");
        return 0;
      }
      dfs(i, 0);
      udah = 1;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(ada[i][j]) {
        if(c[i] + c[j] == 1) {
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  for(int i = 1; i <= n; i++) {
    if(c[i] == -1) {
      printf("b");
    } else if(c[i] == 0) {
      printf("a");
    } else {
      printf("c");
    }
  }
  
  return 0;
}
