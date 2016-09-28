#include <bits/stdc++.h>

using namespace std;

const int N = 20;

char s[N];
int a[N];
int cnt[N];

bool sip() {
  bool all = 1;
  for (int i = 1; i <= 5; i++) if (cnt[i] == 0) {
    all = 0;
  }
  return all;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - 'A' + 1;
      cnt[a[i]]++;
    }
    bool ada = 0;
    if (sip()) ada = 1;
    for (int p = 0; p < n; p++) {
      cnt[a[p]]--;
      for (int i = 0; i < n; i++) {
        if (i == p) continue;
        cnt[a[i]]--;
        cnt[a[i] + a[p]]++;
        if (sip()) ada = 1;
        cnt[a[i] + a[p]]--;
        cnt[a[i]]++;
      }
      cnt[a[p]]++;
    }
    //cout << ada << endl;
    //if (!ada) puts("sampe 1 hilang ga ada");
    for (int p = 0; p < n; p++) {
      cnt[a[p]]--;
      for (int q = 0; q < n; q++) {
        if (p == q) continue;
        cnt[a[q]]--;
        for (int i = 0; i < n; i++) {
          if (i == p || i == q) continue;
          cnt[a[i]]--;
          cnt[a[i] + a[p]]++;
          for (int j = 0; j < n; j++) {
            if (j == i || j == p || j == q) continue;
            cnt[a[j]]--;
            cnt[a[j] + a[q]]++;
            if (sip()) ada = 1;
            cnt[a[j] + a[q]]--;
            cnt[a[j]]++;
          }
          cnt[a[i] + a[p]]--;
          cnt[a[i]]++;
        }
        cnt[a[q]]++;
      }
      cnt[a[p]]++;
    }
    
    puts(ada? "YES" : "NO");
  }
  
  return 0;
}
