#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
bool done[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(1LL * n * (n - 1) / 2 < 2 * m) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[min(u, v)].push_back(v);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      done[j] = 0;
    }
    for(auto it : edge[i]) {
      done[it] = 1;
    }
    for(int j = i + 1; j <= n; j++) {
      if(!done[j] && m) {
        printf("%d %d\n", i, j);
        m--;
      }
    }
  }
  
  return 0;
}
