#include <bits/stdc++.h>

using namespace std;

const int N = 300;

bool is[N];

int main(){
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case #%d: %s\n", tt, is[a + b]? "Tidak Cocok" : "Cocok");
  }
  return 0;
};