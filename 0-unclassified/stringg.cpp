#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N];
char be[N];
char p[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int m;
  scanf("%d", &m);
  while(m--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--; r--;
    int cnt = r - l + 1;
    k %= cnt;
    for(int i = 0; i < cnt; i++) {
      be[(i + k) % cnt] = s[l + i];
    }
    for(int i = 0; i < cnt; i++) {
      s[l + i] = be[i];
    }
  }
  printf("%s\n", s);
  return 0;
}
