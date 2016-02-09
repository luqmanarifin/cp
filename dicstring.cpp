#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5;

int wajib[26];
char s[105][N];
char a[105][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(wajib, 0, sizeof(wajib));
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    for(int i = 0; i < m; i++) {
      scanf("%s", a[i]);
    }
    for(int i = 0; i < n; i++) {
      int cnt[26];
      memset(cnt, 0, sizeof(cnt));
      int len = strlen(s[i]);
      for(int j = 0; j < len; j++) {
        cnt[s[i][j] - 'a']++;
      }
      for(int j = 0; j < 26; j++) {
        wajib[j] = max(wajib[j], cnt[j]);
      }
    }
    for(int i = 0; i < m; i++) {
      int cnt[26];
      memset(cnt, 0, sizeof(cnt));
      int len = strlen(a[i]);
      for(int j = 0; j < len; j++) {
        cnt[a[i][j] - 'a']++;
      }
      int kurang = 0, same = 1;
      for(int j = 0; j < 26; j++) {
        if(cnt[j] < wajib[j]) {
          kurang += wajib[j] - cnt[j];
        }
        if(cnt[j] != wajib[j]) {
          same = 0;
        }
      }
      if(kurang > 0) {
        printf("No %d\n", kurang);
      } else if(same) {
        puts("Yes Yes");
      } else {
        puts("Yes No");
      }
    }
  }
  
  return 0;
}
