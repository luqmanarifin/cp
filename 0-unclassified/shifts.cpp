#include <bits/stdc++.h>

using namespace std;

char s[10005];
int need[105][10005];
int aft[10005];
int bef[10005];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s);
    bool allZero = 1;
    for(int j = 0; j < m; j++) {
      if(s[j] == '1') {
        allZero = 0;
        break;
      }
    }
    if(allZero) {
      puts("-1");
      return 0;
    }
    for(int j = 0; j < m; j++) {
      aft[j] = m;
      bef[j] = -1;
    }
    for(int j = 0; j < m; j++) {
      if(j) bef[j] = bef[j - 1];
      if(s[j] == '1') {
        bef[j] = j;
      }
    }
    
    for(int j = m - 1; j >= 0; j--) {
      if(j < m - 1) aft[j] = aft[j + 1];
      if(s[j] == '1') {
        aft[j] = j;
      }
    }
    for(int j = 0; j < m; j++) {
      int aa = 1e9;
      int bb = 1e9;
      if(aft[j] == m) {
        aa = m - j + aft[0];
      } else {
        aa = aft[j] - j;
      }
      if(bef[j] == -1) {
        bb = m + j - bef[m - 1];
      } else {
        bb = j - bef[j];
      }
      need[i][j] = min(aa, bb);
    }
  }
  int ans = 1e9;
  for(int j = 0; j < m; j++) {
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += need[i][j];
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  
  return 0;
}