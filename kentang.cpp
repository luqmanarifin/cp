#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 10;
const int inf = 1e9;

int dp[N];
bool done[N];
char s[5][5];
int t[15];

int main() {
  for(int i = 0; i < 9; i++) {
    t[i] |= (1 << i);
    if(i != 2 && i != 5 && i != 8) {
      t[i] |= (1 << (i + 1));
    }
    if(i != 0 && i != 3 && i != 6) {
      t[i] |= (1 << (i - 1));
    }
    if(i != 0 && i != 1 && i != 2) {
      t[i] |= (1 << (i - 3));
    }
    if(i != 6 && i != 7 && i != 8) {
      t[i] |= (1 << (i + 3));
    }
  }
  
  queue<int> q;
  q.push(0);
  done[0] = 1;
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(int i = 0; i < 9; i++) {
      int d = now ^ t[i];
      if(!done[d]) {
        done[d] = 1;
        dp[d] = dp[now] + 1;
        q.push(d);
      }
    }
  }
  for(int i = 1; i < (1 << 9); i++) {
    assert(dp[i] != 0);
  }
  
  int p;
  scanf("%d", &p);
  while(p--) {
    for(int i = 0; i < 3; i++) {
      scanf("%s", s[i]);
    }
    int mask = 0;
    for(int i = 0; i < 9; i++) {
      if(s[i / 3][i % 3] == '*') {
        mask |= (1 << i);
      }
    }
    printf("%d\n", dp[mask]);
  }
  
  return 0;
}
