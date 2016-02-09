#include <bits/stdc++.h>

using namespace std;

vector<string> s;
vector<vector<bool>> isl, con, bri;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
string str[] = {"BB", "BX", "#X", "##", "X#", "XB"};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs_island(int x, int y) {
  if(isl[x][y]) return;
  isl[x][y] = 1;
  for(int d = 0; d < 4; d++) {
    int xi = x + dx[d];
    int xj = y + dy[d];
    if(valid(xi, xj) && (s[xi][xj] == '#' || s[xi][xj] == 'X')) {
      dfs_island(xi, xj);
    }
  }
}

// st == 1 lagi di bridge
void dfs_buses(int x, int y) {
  if(con[x][y]) return;
  con[x][y] = 1;
  for(int d = 0; d < 4; d++) {
    int xi = x + dx[d];
    int xj = y + dy[d];
    if(valid(xi, xj)) {
      for(int u = 0; u < 6; u++) {
        if(s[x][y] == str[u][0] && s[xi][xj] == str[u][1]) {
          dfs_buses(xi, xj);
        }
      }
    }
  }
}

void dfs_bridges(int x, int y) {
  if(bri[x][y]) return;
  bri[x][y] = 1;
  for(int d = 0; d < 4; d++) {
    int xi = x + dx[d];
    int xj = y + dy[d];
    if(valid(xi, xj) && s[xi][xj] == 'B') {
      dfs_bridges(xi, xj);
    }
  }
}

int main() {
  try {
  ios_base::sync_with_stdio(0);
  
  int t = 0;
  string buffer;
  getline(cin, buffer);
  while(buffer.size() > 0) {
    ++t;
    if(t > 1) printf("\n");
    s.clear();
    do {
      //printf("BUFFER %s\n", buffer.c_str());
      s.push_back(buffer);
      getline(cin, buffer);
    } while(buffer.size());
    
    n = s.size();
    m = s[0].size();
    //printf("%d %d\n", n, m);
    isl.assign(n, vector<bool>(m));
    con.assign(n, vector<bool>(m));
    bri.assign(n, vector<bool>(m));
    //puts("JANCOK");
    //printf("size %d %d\n", isl.size(), isl[0].size());
    int islands = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if((s[i][j] == '#' || s[i][j] == 'X') && !isl[i][j]) {
          islands++;
          dfs_island(i, j);
        }
      }
    }
    //puts("island done");
    
    int buses = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if((s[i][j] == '#' || s[i][j] == 'X' || s[i][j] == 'B') && !con[i][j]) {
          buses++;
          dfs_buses(i, j);
        }
      }
    }
    
    int bridges = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(s[i][j] == 'B' && !bri[i][j]) {
          bridges++;
          dfs_bridges(i, j);
        }
      }
    }
    printf("Map %d\n", t);
    printf("islands: %d\n", islands);
    printf("bridges: %d\n", bridges);
    printf("buses needed: %d\n", buses);
    
    getline(cin, buffer);
  }
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  return 0;
}
