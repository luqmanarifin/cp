#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int Q = 1005;

int x[N], y[N];
vector<int> p[Q];

int ascending_y(int l, int r) {
  return y[l] < y[r];
}

int descending_y(int l, int r) {
  return y[l] > y[r];
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, y + i);
    p[x[i] / Q].push_back(i);
  }
  for(int i = 0; i < Q; i++) {
    if(i % 2) {
      sort(p[i].begin(), p[i].end(), ascending_y);
    } else {
      sort(p[i].begin(), p[i].end(), descending_y);
    }
    for(auto it : p[i]) {
      printf("%d ", it);
    }
  }
  
  return 0;
}
