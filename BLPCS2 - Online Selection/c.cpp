#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool is[N];
vector<int> p;
int a[N][N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      p.push_back(i);
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for(auto n : p) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        a[i][j] = i * n + j + 1;
      }
    }
    int ada = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i + 1 < n) {
          if(__gcd(a[i][j], a[i + 1][j]) != 1) {
            ada++;
          }
        }
        if(j + 1 < n) {
          if(__gcd(a[i][j], a[i][j + 1]) != 1) {
            ada++;
          }
        }
      }
    }
    assert(ada <= n);
    printf("%d done\n", n);
  }
  return 0;
}
