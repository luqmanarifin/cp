#include <bits/stdc++.h>

using namespace std;

const int M = 2e6 + 5;

bool is[M];
vector<int> prime;

int main() {
  for(int i = 2; i < M; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < M; j += i) {
        is[j] = 1;
      }
      prime.push_back(i);
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", 1LL * prime[n] * prime[n]);
  }
  return 0;
}
