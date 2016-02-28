#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool is[N];

int main() {
  int n;
  vector<int> ans;
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  scanf("%d", &n);
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i; j <= n; j *= i) {
        ans.push_back(j);
      }
    }
  }
  printf("%d\n", ans.size());
  for(auto it : ans) {
    printf("%d ", it);
  }
  return 0;
}