#include <bits/stdc++.h>

using namespace std;

string str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[10][26];
char s[2005];
int must[10];

int all[26];
int st[10];

int dfs(int p) {
  if(p == 10) {
    for(int i = 0; i < 26; i++) {
      if(all[i]) return 0;
    }
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < st[i]; j++) {
        printf("%d", i);
      }
    }
    printf("\n");
    return 1;
  }
  if(must[p]) {
    for(int i = 0; i < str[p].size(); i++) {
      if(cnt[p][str[p][i] - 'A'] == 1) {
        bool good = 1;
        int kali = all[str[p][i] - 'A'];
        for(int j = 0; j < 26; j++) {
          all[j] -= kali * cnt[p][j];
          if(all[j] < 0) good = 0;
        }
        if(good) {
          st[p] = kali;
          if(dfs(p + 1)) return 1;
        }
        for(int j = 0; j < 26; j++) {
          all[j] += kali * cnt[p][j];
        }
      }
    }
    return 0;
  }
  for(int kali = 0; ; kali++) {
    bool good = 1;
    for(int i = 0; i < 26; i++) {
      all[i] -= kali * cnt[p][i];
      if(all[i] < 0) good = 0;
    }
    if(good) {
      st[p] = kali;
      if(dfs(p + 1)) return 1;
    }
    for(int i = 0; i < 26; i++) {
      all[i] += kali * cnt[p][i];
    }
    if(!good) break;
  }
  return 0;
}

int main() {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < str[i].size(); j++) {
      cnt[i][str[i][j] - 'A']++;
    }
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < str[i].size(); j++) {
      int count = 0;
      for(int k = 0; k < 10; k++) {
        count += cnt[k][str[i][j] - 'A'];
      }
      if(count == 1) {
        must[i] = 1;
        //printf("%d must\n", i);
      }
    }
  }
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(all, 0, sizeof(all));
    
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
      all[s[i] - 'A']++;
    }
    printf("Case #%d: ", tt);
    dfs(0);
    cerr << tt << " done!" << endl;
  }
  return 0;
}