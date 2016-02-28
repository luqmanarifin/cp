#include <bits/stdc++.h>

using namespace std;

const int N = 16;

int pos[] = {1, 2, 3, 5, 9};

int a[N][N], f[5][N];
int best[N], worst[N], n;
int vis[1 << N];

void brute(int s, int can, int mask) {
  if(vis[can]) return;
  if(__builtin_popcount(can) == 1) {
    int who = (__builtin_clz(can) ^ 31);
    best[who] = max(best[who], s);
    worst[who] = min(worst[who], s);
    return;
  }
  if(mask == 0) {
    int win = 0;
    for(int i = 0; i < n; i++) {
      if(f[s][i] != -1) {
        int j = f[s][i];
        if(a[i][j]) {
          best[j] = max(best[j], s);
          worst[j] = min(worst[j], s);
        } else {
          best[i] = max(best[i], s);
          worst[i] = min(worst[i], s);
        }
        win |= (a[i][j] ? (1 << i) : (1 << j));
      }
    }
    brute(s + 1, win, win);
    return;
  }
  int now = (__builtin_clz(mask) ^ 31);
  mask ^= (1 << now);
  for(int i = now - 1; i >= 0; i--) {
    if(mask & (1 << i)) {
      f[s][now] = i;
      brute(s, can, mask ^ (1 << i));
      f[s][now] = -1;
    }
  }
  if(can == (mask ^ (1 << now))) vis[can] = 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(f, -1, sizeof(f));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < N; i++) {
      best[i] = -N;
      worst[i] = N;
    }
    
    scanf("%d", &n);
    int k = (__builtin_clz(n) ^ 31);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    brute(0, (1 << n) - 1, (1 << n) - 1);
    printf("Case #%d:\n", tt);
    for(int i = 0; i < n; i++) {
      printf("%d %d\n", pos[k - best[i]], pos[k - worst[i]]);
    }
    cerr << tt << " done!" << endl;
  }
  return 0;
}
