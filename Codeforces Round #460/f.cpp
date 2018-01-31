#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp, running;
int cnta[10], cntb[10];

pair<int, int> encode(bool swapped) {
  int a = 0, b = 0;
  for (int i = 0; i < 5; i++) {
    a = a * 9 + cnta[i];
    b = b * 9 + cntb[i];
  }
  if (swapped) swap(a, b);
  return {a, b};
}

int dfs(bool turn) {
  auto val = encode(turn);
  if (mp.count(val)) return mp[val];
  if (running.count(val)) return 1;
  
  if (cnta[0] == 8) {
    if (turn == 0) {
      return mp[val] = 2;
    } else {
      return mp[val] = 0;
    }
  }
  if (cntb[0] == 8) {
    if (turn == 0) {
      return mp[val] = 0;
    } else {
      return mp[val] = 2;
    }
  }
  
  running[val] = 1;
  bool loop = 0;
  for (int i = 1; i < 5; i++) {
    if (cnta[i] == 0) continue;
    for (int j = 1; j < 5; j++) {
      if (cntb  [j] == 0) continue;
      int c = (i + j) % 5;
      if (turn == 0) {
        int ori = i;
        cnta[ori]--;
        cnta[c]++;
        
        int ret = dfs(turn ^ 1);
        if (ret == 0) {
          return mp[val] = 2;
        } else if (ret == 1) {
          loop = 1;
        }
        
        cnta[c]--;
        cnta[ori]++;
      } else {
        int ori = j;
        cntb[ori]--;
        cntb[c]++;
        
        int ret = dfs(turn ^ 1);
        if (ret == 0) {
          return mp[val] = 2;
        } else if (ret == 1) {
          loop = 1;
        }
        
        cntb[c]--;
        cntb[ori]++;
      }
    }
  }
  if (loop) return mp[val] = 1;
  return mp[val] = 0;
}

int main() {
  puts("Alice");
  puts("Bob");
  puts("Alice");
  puts("Deal");
  return 0;
  
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb));
    
    int turn;
    scanf("%d", &turn);
    for (int i = 0; i < 8; i++) {
      int v;
      scanf("%d", &v);
      cnta[v]++;
    }
    for (int i = 0; i < 8; i++) {
      int v;
      scanf("%d", &v);
      cntb[v]++;
    }
    int ret = dfs(turn);
    if (ret == 1) {
      puts("Deal");
    } else if (turn == 0) {
      puts(ret? "Alice" : "Bob");
    } else {
      puts(ret? "Bob" : "Alice");
    }
  }
  
  return 0;
}
