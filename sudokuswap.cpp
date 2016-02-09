#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int a[10][10];
int temp[10];
vector<pair<int, int>> need[10][10];

bool valid() {
  for(int i = 0; i < 9; i++) {
    memset(temp, 0, sizeof(temp));
    for(int j = 0; j < 9; j++) {
      temp[a[i][j]]++;
    }
    for(int j = 0; j < 9; j++) {
      if(temp[j] != 1) return 0;
    }
  }
  for(int j = 0; j < 9; j++) {
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < 9; i++) {
      temp[a[i][j]]++;
    }
    for(int i = 0; i < 9; i++) {
      if(temp[i] != 1) return 0;
    }
  }
  for(int at = 0; at < 9; at++) {
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < 9; i++) {
      temp[a[at / 3 * 3 + i / 3][at % 3 * 3 + i % 3]]++;
    }
    for(int i = 0; i < 9; i++) {
      if(temp[i] != 1) return 0;
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        need[i][j].clear();
      }
    }
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        scanf("%d", &a[i][j]);
        a[i][j]--;
      }
    }
    // horizontal
    for(int i = 0; i < 9; i++) {
      memset(temp, 0, sizeof(temp));
      for(int j = 0; j < 9; j++) {
        temp[a[i][j]]++;
      }
      int dua = -1, nol = -1;
      for(int j = 0; j < 9; j++) {
        if(temp[j] == 2) dua = j;
        else if(temp[j] == 0) nol = j;
      }
      if(dua == -1 && nol == -1) {
        continue;
      }
      for(int j = 0; j < 9; j++) {
        if(a[i][j] == dua) {
          need[dua][nol].emplace_back(i, j);
        }
      }
    }
    // vertikal
    for(int j = 0; j < 9; j++) {
      memset(temp, 0, sizeof(temp));
      for(int i = 0; i < 9; i++) {
        temp[a[i][j]]++;
      }
      int dua = -1, nol = -1;
      for(int i = 0; i < 9; i++) {
        if(temp[i] == 2) dua = i;
        else if(temp[i] == 0) nol = i;
      }
      if(dua == -1 && nol == -1) {
        continue;
      }
      for(int i = 0; i < 9; i++) {
        if(a[i][j] == dua) {
          need[dua][nol].emplace_back(i, j);
        }
      }
    }
    // grouping
    for(int at = 0; at < 9; at++) {
      memset(temp, 0, sizeof(temp));
      for(int i = 0; i < 9; i++) {
        temp[a[at / 3 * 3 + i / 3][at % 3 * 3 + i % 3]]++;
      }
      int dua = -1, nol = -1;
      for(int i = 0; i < 9; i++) {
        if(temp[i] == 2) dua = i;
        else if(temp[i] == 0) nol = i;
      }
      if(dua == -1 && nol == -1) {
        continue;
      }
      for(int i = 0; i < 9; i++) {
        if(a[at / 3 * 3 + i / 3][at % 3 * 3 + i % 3] == dua) {
          need[dua][nol].emplace_back(at / 3 * 3 + i / 3, at % 3 * 3 + i % 3);
        }
      }
    }
    
    vector<pair<pair<int, int>, pair<int, int>>> ans; 
    for(int i = 0; i < 9; i++) {
      for(int j = i + 1; j < 9; j++) {
        sort(need[i][j].begin(), need[i][j].end());
        sort(need[j][i].begin(), need[j][i].end());
        need[i][j].resize(distance(need[i][j].begin(), unique(need[i][j].begin(), need[i][j].end())));
        need[j][i].resize(distance(need[j][i].begin(), unique(need[j][i].begin(), need[j][i].end())));
        for(auto it : need[i][j]) {
          for(auto jt : need[j][i]) {
            swap(a[it.x][it.y], a[jt.x][jt.y]);
            if(valid()) {
              ans.emplace_back(it, jt);
            }
            swap(a[it.x][it.y], a[jt.x][jt.y]);
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    printf("Case #%d:\n", tt);
    for(auto it : ans) {
      printf("(%d,%d) <-> (%d,%d)\n", it.x.x + 1, it.x.y + 1, it.y.x + 1, it.y.y + 1);
    }
    if(ans.empty()) {
      puts("Serendipity");
    }
  }
  
  return 0;
}
