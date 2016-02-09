#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int 

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c)
  }
  
  
  return 0;
}
