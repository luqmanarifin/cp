// Author: Ivan Katanic
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 5050;

enum Color {WHITE, GRAY, BLACK};

Color color[MAX];
int disc[MAX];
int tick;

int dfs(int x, int dad, vector<int> E[MAX], vector<int> ans[MAX]) {
  color[x] = GRAY;
  int lw = disc[x] = tick++;

  for (int y: E[x]) {
    if (y == dad) {
      dad = -1;
    } else if (color[y] == BLACK) {
      ans[x].push_back(y);
    } else if (color[y] == GRAY) {
      lw = min(lw, disc[y]);
      ans[x].push_back(y);
    } else if (color[y] == WHITE) {
      int lwy = dfs(y, x, E, ans);
      if (lwy <= disc[x]) {
        ans[x].push_back(y);
        ans[y].push_back(x);
      }
      lw = min(lw, lwy);
    }
  }

  color[x] = BLACK;
  return lw;
}

void removeBridges(int N, vector<int> E[MAX], vector<int> ans[MAX]) {
  for (int i = 0; i < N; ++i)
    ans[i].clear();
  for (int i = 0; i < N; ++i)
    color[i] = WHITE;
  for (int i = 0; i < N; ++i)
    if (color[i] == WHITE) dfs(i, -1, E, ans);
}  

void dfs(int x, vector<int> E[MAX], int ans[MAX]) {
  for (int y: E[x])
    if (ans[y] == -1) {
      ans[y] = ans[x];
      dfs(y, E, ans);
    }
}

void identifyComponents(int N, vector<int> E[MAX], int ans[MAX]) {
  for (int i = 0; i < N; ++i) 
    ans[i] = -1;
  for (int i = 0; i < N; ++i)
    if (ans[i] == -1) {
      ans[i] = i;
      dfs(i, E, ans);
    }
}

void identify2ConnectedComponents(int N, vector<int> E[MAX], int ans[MAX]) {
  static vector<int> F[MAX];
  removeBridges(N, E, F);
  identifyComponents(N, F, ans);
}

const int P = 9973;
const int mod = 1e9 + 7;

vector<int> E[MAX];
int c1[MAX]; // 1-edge
int c2[MAX]; // 2-edge
int h[MAX];

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  identifyComponents(N, E, c1);
  identify2ConnectedComponents(N, E, c2);
  
  for (int x = 0; x < N; ++x)
    for (int i = 0; i < (int)E[x].size(); ++i) {
      int y = E[x][i];
      if (x < y) {
        swap(E[x][i], E[x].back());
        E[x].pop_back();

        for (int j = 0; j < (int)E[y].size(); ++j)
          if (E[y][j] == x) {
            E[y].erase(E[y].begin() + j);
            break;
          }
             
        static int id[MAX];
        identify2ConnectedComponents(N, E, id);
        for (int j = 0; j < N; ++j)
          h[j] = (1LL*h[j]*P + id[j]) % mod;
        
        E[y].push_back(x);
        E[x].push_back(y);
        swap(E[x][i], E[x].back());
      }
    }
  
  int ans = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < i; ++j)
      if (c1[i] != c1[j]) {
        ans += 0;
      } else if (c2[i] != c2[j]) {
        ans += 1;
      } else if (h[i] != h[j]) {
        ans += 2;
      } else {
        ans += 3;
      }

  printf("%d\n", ans);
  return 0;
}
