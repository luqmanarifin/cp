#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 505;
 
bool done[N * N];
 
int solve(vector<int> nice) {
  memset(done, 0, sizeof(done));
  int sum = 0;
  for(auto it : nice) sum += it;
  done[sum / 2] = 1;
  for(auto it : nice) {
    for(int i = it; i <= sum / 2; i++) {
      if(done[i]) {
        done[i - it] = 1;
      }
      if(done[0]) {
        return sum % 2;
      }
    }
  }
  for(int i = 0; i <= sum / 2; i++) {
    if(done[i]) {
      return i * 2 + sum % 2;
    }
  }
  assert(0);
}
 
int a[N];
 
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
      char c;
      if(i) scanf(" %c", &c);
      scanf("%d", a + i);
    }
    if(n < 3) {
      puts("NO");
      continue;
    }
    vector<int> odd, even;
    for(int i = 0; i <= n; i++) {
      if(i % 2) odd.push_back(a[i]);
      else even.push_back(a[i]); 
    }
    int ans = solve(odd) + solve(even);
    printf("%d\n", ans);
  }
  return 0;
}