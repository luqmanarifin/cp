#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool done[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> bad;
  for(int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if(done[a] || a > n) {
      bad.push_back(i);
    } else {
      done[a] = 1;
      ans[i] = a;
    }
  }
  for(int i = 1, p = 0; i <= n; i++) {
    if(!done[i]) {
      ans[bad[p]] = i;
      p++;
    }
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
