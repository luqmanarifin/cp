#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

bool done[N][N];

set<pair<int, int>> all;
char s[N][N];

int main() {
  srand(time(0));
  int n = 2000, m = 2000, k = 300000, q = 300000;
  while(all.size() != k + q) {
    int a = rand() % 2000 + 1;
    int b = rand() % 2000 + 1;
    all.insert(make_pair(a, b));
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      s[i][j] = '.';
    }
  }
  vector<pair<int, int>> query;
  int id = 0;
  for(auto it : all) {
    int a = it.first;
    int b = it.second;
    if(id < k) {
      s[a][b] = 'X';
    } else {
      query.push_back(it);
    }
    id++;
  }
  cerr << "query size " << query.size() << endl;
  puts("junk");
  printf("%d %d %d %d\n", n, m, k, q);
  for(int i = 1; i <= n; i++) printf("%s\n", s[i] + 1);
  for(auto it : query) printf("%d %d\n", it.first, it.second);
  return 0;
}