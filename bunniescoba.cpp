#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int val[N][N];
int to[N * N];

bool done[N * N];
bool ada[N * N];
int at[N];

vector<int> snake[N], bun[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = n - 1; i >= 0; i--) {
    if(i % 2 == 0) {
      int now = (n - 1 - i) * n;
      for(int j = 0; j < n; j++) {
        now++;
        val[i][j] = now;
      }
    } else {
      int now = (n - 1 - i) * n;
      for(int j = n - 1; j >= 0; j--) {
        now++;
        val[i][j] = now;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if('0' <= s[i][j] && s[i][j] <= '9') {
        bun[s[i][j] - '0'].push_back(val[i][j]);
      }
      if('a' <= s[i][j] && s[i][j] <= 'z') {
        snake[s[i][j] - 'a'].push_back(val[i][j]);
      }
    }
  }
  for(int i = 0; i < N; i++) {
    if(snake[i].size()) {
      int mx = max(snake[i][0], snake[i][1]);
      int mn = min(snake[i][0], snake[i][1]);
      to[mx] = mn;
    }
    if(bun[i].size()) {
      int mx = max(bun[i][0], bun[i][1]);
      int mn = min(bun[i][0], bun[i][1]);
      to[mn] = mx;
    }
  }
  /*
  for(int i = 1; i <= n * n; i++) {
    printf("%d ", to[i]);
  }
  printf("\n");
  */
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i = (i + 1) % m) {
    int a, b, ret;
    if(scanf("%d %d", &a, &b) == -1) {
      break;
    }
    
    ada[at[i]] = 0;
    at[i] += a + b;
    //printf("pemain %d ke %d\n", i, at[i]);
    
    done[at[i]] = 1;
    vector<int> vis;
    vis.push_back(at[i]);
    
    while(ada[at[i]] || to[at[i]]) {
      assert(ada[at[i]] ^ to[at[i]]);
      if(ada[at[i]]) {
        at[i]++;
      } else if(to[at[i]]) {
        at[i] = to[at[i]];
      }
      //printf("pemain %d ke %d\n", i, at[i]);
      if(done[at[i]]) {
        printf("PLAYER %d WINS BY EVIL CYCLE!\n", i + 1);
        return 0;
      }
      done[at[i]] = 1;
      vis.push_back(at[i]);
    }
    for(auto it : vis) {
      done[it] = 0;
    }
    vis.clear();
    
    if(a == b) {
      scanf("%d", &a);
      at[i] += a;
      if(at[i] >= n * n) goto PRINT;
      
      done[at[i]] = 1;
      vis.push_back(at[i]);
      
      while(ada[at[i]] || to[at[i]]) {
        assert(ada[at[i]] ^ to[at[i]]);
        if(ada[at[i]]) {
          at[i]++;
        } else if(to[at[i]]) {
          at[i] = to[at[i]];
        }
        //printf("pemain %d ke %d\n", i, at[i]);
        if(done[at[i]]) {
          printf("PLAYER %d WINS BY EVIL CYCLE!\n", i + 1);
          return 0;
        }
        done[at[i]] = 1;
        vis.push_back(at[i]);
      }
      for(auto it : vis) {
        done[it] = 0;
      }
      vis.clear();
    }
    
    ada[at[i]] = 1;
  }
  PRINT:;
  for(int i = 0; i < m; i++) {
    if(i) printf(" ");
    printf("%d", at[i]);
  }
  printf("\n");
  return 0;
}
