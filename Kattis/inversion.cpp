#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int til[N];
char s[N];

unsigned long long bit[N], a[N];
int ans[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int last = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'B') {
      bit[i / 64] |= (1LL << (i % 64));
    } else {
      last = i;
    }
  }
  til[0] = last;
  for(int i = 1; last >= 0; i++) {
    til[i] = --last;
  }
  for(int i = 0; i < N; i++) {
    til[i] /= 64;
  }
  for()
  
  for(int i = 1; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}