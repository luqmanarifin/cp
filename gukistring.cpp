#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int cnt[26];
int nedb[26];
int nedc[26];
char sa[N], sb[N], sc[N];

int main() {
  int n;
  scanf("%s", sa);
  n = strlen(sa);
  for(int i = 0; i < n; i++) {
    cnt[sa[i] - 'a']++;
  }
  int len = n;
  
  scanf("%s", sb);
  n = strlen(sb);
  for(int i = 0; i < n; i++) {
    nedb[sb[i] - 'a']++;
  }
  
  scanf("%s", sc);
  n = strlen(sc);
  for(int i = 0; i < n; i++) {
    nedc[sc[i] - 'a']++;
  }
  
  int maks = 0, b = 0, c = 0;
  for(int i = 0; i <= len; i++) {
    int tmp[26];
    for(int j = 0; j < 26; j++) {
      tmp[j] = cnt[j];
    }
    bool can = 1;
    for(int j = 0; j < 26; j++) {
      if(i * nedb[j] > tmp[j]) {
        can = 0;
      }
      tmp[j] -= i * nedb[j];
    }
    if(!can) {
      break;
    }
    int cntc = inf;
    for(int j = 0; j < 26; j++) {
      if(nedc[j] > 0) {
        cntc = min(cntc, tmp[j] / nedc[j]);
      }
    }
    if(i + cntc > maks) {
      maks = i + cntc;
      b = i;
      c = cntc;
    }
  }
  for(int i = 0; i < 26; i++) {
    cnt[i] -= b * nedb[i];
    cnt[i] -= c * nedc[i];
  }
  for(int i = 0; i < b; i++) {
    printf("%s", sb);
  }
  for(int i = 0; i < c; i++) {
    printf("%s", sc);
  }
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < cnt[i]; j++) {
      printf("%c", i + 'a');
    }
  }
  return 0;
}
