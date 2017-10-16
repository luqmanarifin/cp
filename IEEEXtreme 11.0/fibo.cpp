#include <bits/stdc++.h>

using namespace std;

const long long mod = 10;
const int N = 15;

int vis[N][N];

int main() {
  memset(vis, -1, sizeof(vis));
  
  int a = 1, b = 2;
  vector<pair<int, int>> p; 
  vis[a][b] = 0;
  p.emplace_back(a, b);
  //puts("cok");
  for (int i = 1; ; i++) {
    int c = (a + b) % mod;
    a = b;
    b = c;
    //printf("%d %d\n", a, b);
    if (vis[a][b] != -1) break;
    vis[a][b] = i;
    p.emplace_back(a, b);
  }
  int offset = vis[a][b];
  int size = p.size() - vis[a][b];
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      n -= 2;
      if (n < p.size()) {
        printf("%d\n", p[n].second);
      } else {
        printf("%d\n", p[(n - offset) % size + offset].second);
      }
    }
  }

  return 0;
}
