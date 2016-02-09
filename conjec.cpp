#include <bits/stdc++.h>

using namespace std;

const int N = 32005;

bool is[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
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
    vector<pair<int, int>> ans;
    for(int i = 2; i <= n/2; i++) {
      if(!is[i] && !is[n - i]) {
        ans.emplace_back(i, n - i);
      }
    }
    printf("%d has %d representation(s)\n", n, ans.size());
    for(auto it : ans) {
      printf("%d+%d\n", it.first, it.second);
    }
    printf("\n");
  }
  
  return 0;
}
