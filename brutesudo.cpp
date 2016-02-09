#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int a[10][10];
int temp[10];

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
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        scanf("%d", &a[i][j]);
        a[i][j]--;
      }
    }
    
    vector<pair<pair<int, int>, pair<int, int>>> ans; 
    
    for(int it = 0; it < 81; it++) {
      int i = it / 9, j = it % 9;
      for(int jt = it + 1; jt < 81; jt++) {
        int k = jt / 9, l = jt % 9;
        if(a[i][j] == a[k][l]) continue;
        swap(a[i][j], a[k][l]);
        if(valid()) {
          ans.emplace_back(make_pair(i, j), make_pair(k, l));
        }
        swap(a[i][j], a[k][l]);
      }
    }
    
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
