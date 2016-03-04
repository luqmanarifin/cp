#include <bits/stdc++.h>

using namespace std;

const int N = 3e7 + 5;

bool is[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      if(i > 28e6) {
        printf("%d\n", i);
      }
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  return 0;
}
