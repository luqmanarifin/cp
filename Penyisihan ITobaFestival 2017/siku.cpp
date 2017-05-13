#include <bits/stdc++.h>

using namespace std;

const int N = 5;
const int BIG = 2e6 + 5;

vector<pair<int, int>> v[BIG];
int root[BIG];

bool solve(int a, int b) {
  for (auto i : v[a]) {
    for (auto j : v[b]) {
      if (i.first == j.second) continue;
      if (i.first < j.second) {
        int x = j.second - i.first;
        int y = i.second + j.first;
        int z = x * x + y * y;
        if (z == a * a + b * b) return 1;
      } else {
        int x = i.first - j.second;
        int y = i.second + j.first;
        int z = x * x + y * y;
        if (z == a * a + b * b) return 1;
      }
    }
  }
  return 0;
}

int main() {
  
  for (int i = 1; i * i < BIG; i++) root[i * i] = i;
  for (int i = 1; i <= 1000; i++) {
    //printf("%d done\n", i);
    for (int j = 1; j <= 1000; j++) {
      int d = i * i + j * j;
      //printf("lala %d %d %d\n", i, j, root[d]);
      if (root[d]) {
        int sq = root[d];
        v[sq].emplace_back(i, j);
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    puts(solve(a, b)? "TRUE" : "FALSE");
  }
  return 0;
}
