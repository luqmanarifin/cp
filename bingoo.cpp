#include <bits/stdc++.h>

using namespace std;

const int n = 5;
const int N = n * n;
const int mod = 1e9 + 7;

int ah[N], ph[N], an[N], pn[N], st[N];
vector<int> vis;
int dp[1 << N];
bool f[n][n];

bool win(int mask, int* p) {
  memset(f, 0, sizeof(f));
  for(int i = 0; i < N; i++) {
    if(mask & (1 << i)) {
      int y = p[i] / n;
      int z = p[i] % n;
      assert(f[y][z] == 0);
      f[y][z] = 1;
    }
  }
  for(int i = 0; i < n; i++) {
    bool all = 1;
    for(int j = 0; j < n; j++) {
      if(!f[i][j]) {
        all = 0;
      }
    }
    if(all) return 1;
  }
  for(int j = 0; j < n; j++) {
    bool all = 1;
    for(int i = 0; i < n; i++) {
      if(!f[i][j]) {
        all = 0;
      }
    }
    if(all) return 1;
  }
  bool all = 1;
  for(int i = 0; i < n; i++) {
    if(!f[i][i]) all = 0;
  }
  if(all) return 1;
  
  all = 1;
  for(int i = 0; i < n; i++) {
    if(!f[i][n - i - 1]) all = 0;
  }
  if(all) return 1;
  return 0;
}

int dfs(int mask) {
  if(dp[mask] != -1) return dp[mask];
  vis.push_back(mask);
  int& ret = dp[mask] = 0;
  bool harry_win = win(mask, ph);
  bool hermione_win = win(mask, pn);
  
  if(harry_win && !hermione_win) {
    return ret = 1;
  } else if(harry_win || hermione_win) {
    return ret = 0;
  }
  
  if(__builtin_popcount(mask) % 2) {
    int t = __builtin_popcount(mask) / 2;
    while(mask & (1 << st[t])) {
      t++;
    }
    ret = dfs(mask | (1 << st[t]));
  } else {
    for(int i = 0; i < N; i++) {
      if((mask & (1 << i)) == 0) {
        ret += dfs(mask | (1 << i));
        if(ret >= mod) ret -= mod;
      }
    }
  }
  return ret;
}

void print(int ret, int* p) {
  int mask = 0;
  for(int i = 0; i < N; i++) {
    if(ret & (1 << i)) {
      mask |= (1 << p[i]);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int c = i * n + j;
      if(mask & (1 << c)) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  memset(dp, -1, sizeof(dp));
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      scanf("%d", ah + i);
      ah[i]--;
      ph[ah[i]] = i;
    }
    for(int i = 0; i < N; i++) {
      scanf("%d", an + i);
      an[i]--;
      pn[an[i]] = i;
    }
    for(int i = 0; i < N; i++) {
      scanf("%d", st + i);
      st[i]--;
    }
    /*
    for(int i = 0; i < N; i++) {
      printf("%d ", ph[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
      printf("%d ", pn[i]);
    }
    printf("\n");
    */
    printf("%d\n", dfs(0));
    for(auto it : vis) {
      //printf("%d %d\n", it, dp[it]);
      dp[it] = -1;
    }
    //printf("%d node discovered\n", vis.size());
    vis.clear();
  }
  return 0;
}
