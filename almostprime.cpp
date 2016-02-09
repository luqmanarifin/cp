#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

bool f[N];
bool is[N];

vector<int> p;

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      p.push_back(i);
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for(auto i : p) {
    for(auto j : p) {
      if(i == j) continue;
      int ni = i;
      for(int ci = 1; ni < N; ci++) {
        int nj = j;
        for(int cj = 1; ; cj++) {
          if(ni * nj >= N) break;
          //printf("%d\n", ni * nj);
          f[ni * nj] = 1;
          nj *= j;
        }
        ni *= i;
      }
    }
  }
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += f[i];
    //if(f[i]) cout << i << endl;
  }
  cout << ans << endl;
  return 0;
}
