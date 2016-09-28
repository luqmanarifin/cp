#include <bits/stdc++.h>

using namespace std;

const int BASE = 11;
const int N = 1005;

char mir[] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y' };
int pos[256];

char s[N];
int a[N];

int main() {
  long long C = 11;
  for (int i = 0; i < C; ++i) {
    pos[mir[i]] = i;
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    
    int k;
    scanf("%d %s", &k, s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) a[n - 1 - i] = pos[s[i]];
    for (int i = 0; i < N; i++) {
      a[i] += k % BASE;
      k /= BASE;
      a[i + 1] += a[i] / BASE;
      a[i] = a[i] % BASE;
    }
    int best = n - 1;
    for (int i = n; i < N; i++) {
      bool ada = 0;
      for (int j = i; j < N; j++) if (a[j]) ada = 1;
      if (ada) {
        int j = i;
        while (a[j] == 0) {
          a[j] = BASE - 1;
          j++;
        }
        a[j]--;
        best = i;
      } else {
        break;
      }
    }
    for (int i = best; i >= 0; i--) printf("%c", mir[a[i]]); printf("\n");
  }
  
  return 0;
}
