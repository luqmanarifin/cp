
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[10], ans[10];

void print(int n) {
  while (n--) printf("9"); printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    if (n % 2) {
      print(n - 1);
      continue;
    }
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    bool found = 0;
    for (int i = n - 1; i >= 0; i--) {
      cnt[s[i] - '0']--;
      int free = n - i - 1;
      for (int j = s[i] - '0' - 1; j >= 0; j--) {
        if (j == 0 && i == 0) continue;
        cnt[j]++;
        
        int single = 0;
        for (int k = 0; k <= 9; k++) if (cnt[k] % 2) single++;
        int need = single;
        if (need <= free) {
          //printf("found %d %d\n", i, j);
          for (int it = 0; it < i; it++) printf("%c", s[it]);
          printf("%d", j);
          for (int k = 0; k <= 9; k++) {
            if (cnt[k] % 2) {
              free--;
              ans[k]++;
            }
          }
          ans[9] += free;
          for (int k = 9; k >= 0; k--) while (ans[k]--) printf("%d", k);
          printf("\n");
          found = 1;
          goto niki;
        }
        
        cnt[j]--;
      }
    }
    niki:;
    if (!found) print(n - 2);
  }

  return 0;
}
