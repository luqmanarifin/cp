#include <bits/stdc++.h>

using namespace std;

int MAX = 1e9;
int MIN = 1;
int MID = 1e7;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (n == 1) {
    puts("0");
    return 0;
  }
  if (n == 2 && k == 0) {
    puts("-1");
    return 0;
  }
  if (n == 3 && k == 0) {
    puts("-1");
    return 0;
  } 
  vector<tuple<int, int, int>> edges;
  if (k == 0) {
    for (int i = 2; i < n; i++) edges.emplace_back(1, i, MIN++);
    edges.emplace_back(2, n, MIN++);
    edges.emplace_back(1, n, MAX--);
    for (int i = 2; i < n; i++) edges.emplace_back(i, i + 1, MAX--);
  } else {
    for (int i = 1; i <= k; i++) edges.emplace_back(i, i + 1, MID++);
    for (int i = k + 2; i <= n; i++) edges.emplace_back(1, i, MIN++);
    for (int i = k + 2; i <= n; i++) edges.emplace_back(2, i, MAX--);
  }
  printf("%d\n", edges.size());
  for (auto it : edges) {
    int a, b, c;
    tie(a, b, c) = it;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
