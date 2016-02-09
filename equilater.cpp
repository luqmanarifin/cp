#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

bool is[N];
bool ans[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      if(i % 4 == 1) {
        for(int j = i; j < N; j += i) {
          ans[j] = 1;
        }
      }
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    puts(ans[n]? "YES" : "NO");
  }
  return 0;
}
