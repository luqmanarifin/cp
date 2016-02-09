#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1005;

char s[N][15];
char can[N][N];
int a[N];

int at[1 << 3];
int rem[3];

int tat[1 << 3];
int trem[3];
int num[3];
int cok[3];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%s", can[i]);
  }
  int ai, aj, ak, ans = -1;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        cok[0] = i;
        cok[1] = j;
        cok[2] = k;
        do {
          memset(at, 0, sizeof(at));
          rem[0] = a[cok[0]];
          rem[1] = a[cok[1]];
          rem[2] = a[cok[2]];
          for(int p = 0; p < m; p++) {
            int mask = 0;
            if(can[cok[0]][p] == '1') mask |= 1;
            if(can[cok[1]][p] == '1') mask |= 2;
            if(can[cok[2]][p] == '1') mask |= 4;
            at[mask]++;
          }
          int got = 0;
          for(int r = 0; r < 3; r++) {
            int del = min(rem[r], at[1 << r]);
            got += del;
            rem[r] -= del;
          }
          for(int r = 0; r < (1 << 3); r++) {
            tat[r] = at[r];
            if(r < 3) trem[r] = rem[r];
          }
          int cur = 0;
          for(int mask = 0; mask < (1 << 3); mask++) {
            int simulasi = 0;
            for(int r = 0; r < (1 << 3); r++) {
              at[r] = tat[r];
              if(r < 3) rem[r] = trem[r];
            }
            for(int r = 0; r < 3; r++) {
              num[0] = num[1] = num[2] = (1 << r);
              int fir, sec;
              if(r == 0) fir = 1, sec = 2;
              else if(r == 1) fir = 0, sec = 2;
              else fir = 0, sec = 1;
              
              if(mask & (1 << r)) num[0] |= (1 << fir), num[1] |= (1 << sec);
              else num[1] |= (1 << fir), num[0] |= (1 << sec);
              num[2] |= (1 << fir) | (1 << sec);
              
              for(int u = 0; u < 3; u++) {
                int del = min(rem[r], at[num[u]]);
                simulasi += del;
                rem[r] -= del;
                at[num[u]] -= del;
              }
            }
            cur = max(cur, simulasi);
          }
          if(cur + got > ans) {
            ans = cur + got;
            ai = cok[0]; aj = cok[1]; ak = cok[2];
          }
        } while(next_permutation(cok, cok + 3));
      }
    }
  }
  printf("%d\n%s %s %s\n", ans, s[ai], s[aj], s[ak]);
  return 0;
}
