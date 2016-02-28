#include <bits/stdc++.h>

using namespace std;

int lap[105];
int pos[105];

char a[105];
char c[105];

int nx[105][26];
bool pass[105][26];

int done[105];
int got[105];

int main() {
  int b, d;
  scanf("%d %d %s %s", &b, &d, a, c);
  int la = strlen(a);
  int lc = strlen(c);
  for(int i = 0; i < lc; i++) {
    bool ada = 0;
    for(int j = 0; j < la; j++) {
      if(c[i] == a[j]) {
        ada = 1;
        break;
      }
    }
    if(!ada) {
      puts("0");
      return 0;
    }
  }
  memset(nx, -1, sizeof(nx));
  for(int i = la - 1; i >= 0; i--) {
    for(int j = 0; j < 26; j++) {
      nx[i][j] = nx[i + 1][j];
    }
    nx[i][a[i] - 'a'] = i;
  }
  for(int i = 0; i < la; i++) {
    for(int j = 0; j < 26; j++) {
      if(nx[i][j] == -1) {
        nx[i][j] = nx[0][j];
        pass[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < la; i++) {
    pos[i] = i - 1;
    for(int j = 0; j < lc; j++) {
      if(pos[i] == la - 1) {
        pos[i] = 0;
        lap[i]++;
      } else {
        pos[i]++;
      }
      lap[i] += pass[pos[i]][c[j] - 'a'];
      pos[i] = nx[pos[i]][c[j] - 'a'];
    }
  }
  int p = 0, put = 1, ans = 0;
  while(put <= b) {
    //printf("%d %d %d\n", p, put, ans);
    if(done[p]) {
      int dget = ans - got[p];
      int dput = put - done[p];
      if(dput == 0) {
        goto normal;
      }
      int period = (b - put) / dput;
      if(period == 0) {
        goto normal;
      }
      put += period * dput;
      ans += period * dget;
      done[p] = put;
      got[p] = ans;
      continue;
    }
    normal:;
    done[p] = put;
    got[p] = ans;
    if(put + lap[p] <= b) {
      ans++;
      put += lap[p];
      p = pos[p];
    } else {
      break;
    }
    
    // increment pointer
    if(p < la - 1) {
      p++;
    } else {
      p = 0;
      put++;
    }
  }
  cout << ans / d << endl;
  return 0;
}
