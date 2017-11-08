#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int l[N][2], r[N][2];
int a[N][2], n;

void remove(int i, int j) {
  l[r[i][j]][j] = l[i][j];
  r[l[i][j]][j] = r[i][j];
}

int can(int lim) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      l[i][j] = i - 1;
      r[i][j] = i + 1;
    }    
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] <= lim) {
        remove(i, j);
      }
    }
  }
  for (int j = 0; j < 2; j++) {
    vector<int> p;
    for (int i = r[0][j]; i <= n; i = r[i][j]) {
      p.push_back(a[i][j]);
    }
    if (p.size() % 2) return 0;
    for (int i = 0; i < p.size(); i += 2) {
      if (p[i] != p[i + 1]) return 0;
    }
  }
  return 1;
}


int main() {
  scanf("%d", &n);
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i][j]);
    }
  }
  int l = 0, r = 1e9 + 5;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
