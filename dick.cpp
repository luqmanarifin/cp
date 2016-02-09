#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

const int MAGIC = 16;
const int inf = 1e9;
int pol = (MAGIC + 4) * 10000 + 5;

const int k[][4] = {
  {0, 1, 2, 3},
  {1, ~0, 3, ~2},
  {2, ~3, ~0, 1},
  {3, 2, ~1, ~0}
};

int kali(int a, int b) {
  int neg = 0;
  if(a < 0) {
    neg++;
    a = ~a;
  }
  if(b < 0) {
    neg++;
    b = ~b;
  }
  int ret = k[a][b];
  while(neg--) ret = ~ret;
  return ret;
}
  
int main() {
  char s[pol], source[10005];
  int last[pol][5];
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; tt++) {
    memset(s, 0, sizeof(s));
    memset(source, 0, sizeof(source));
    memset(last, 0, sizeof(last));
    
    long long l, x;
    scanf("%I64d %I64d %s", &l, &x, source);
    if(x > MAGIC) {
      x = (x - MAGIC) % 4 + MAGIC;
    }
    for(int i = 0; i < x; i++) {
      for(int j = 0; j < l; j++) {
        s[i * l + j] = source[j];
      }
    }
    long long len = x * l;
    int now = 0;
    for(int i = len - 1; i >= 0; i--) {
      now = kali(s[i] - 'h', now);
      for(int j = 0; j < 4; j++) {
        last[i][j] = last[i + 1][j];
      }
      if(now >= 0) {
        last[i][now] = i;
      }
    }
    printf("Case #%d: ", tt);
    if(now != -1) {
      puts("NO");
      cerr << tt << " done" << endl; 
      continue;
    }
    
    now = 0;
    bool found = 0;
    for(int i = 0; i < len && !found; i++) {
      now = kali(now, s[i] - 'h');
      if(now == 1 && last[i + 1][3]) {
        found = 1;
      }
    }
    puts(found? "YES" : "NO");
    cerr << tt << " done" << endl; 
  }
  
  return 0;
}
