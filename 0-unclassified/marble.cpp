#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool is[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case #%d: ", tt);
    bool ada = 0;
    for(int i = a; i <= b; i++) {
      if(!is[i]) {
        ada = 1;
        printf("%d\n", i);
        break;
      }
    }
    if(!ada) puts("-1");
  }
  
  return 0;
}
