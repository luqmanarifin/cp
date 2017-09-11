#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+ 5;

char s[N];
int cnt[10];
int need[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - '0']++;
    }
    for (int i = 0; i < 26; i++) {
      int dig = i + 65;
      memset(need, 0, sizeof(need));
      while (dig > 0) {
        need[dig % 10]++;
        dig /= 10;
      }
      bool ok = 1;
      for (int j = 0; j < 10; j++) {
        if (need[j] > cnt[j]) {
          ok = 0;
        }
      }
      if (ok) printf("%c", i + 'A');
    }
    printf("\n");
  }
  
  return 0;
}