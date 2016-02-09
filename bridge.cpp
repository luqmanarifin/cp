#include <bits/stdc++.h>

using namespace std;

int d[1000], k, node;
vector<pair<int,int>> edges;

void build(int b, int start) {
  for(int i = 0; i < k - 1; i++) {
    edges.emplace_back(b, start + i);
    d[start + i]++;
  }
  // degree, vertex
  set<pair<int, int>> s;
  for(int i = start; i < start + k + 1; i++) {
    node = max(node, i);
    s.insert(make_pair(d[i], i));
  }
  for(int i = start; i < start + k + 1; i++) {
    int sisa = k - d[i];
    vector<pair<int, int>> toErase;
    for(auto it : s) {
      if(sisa == 0) {
        break;
      }
      if(it.second <= i) {
        continue;
      }
      if(d[it.second] != it.first) {
        toErase.push_back(it);
      } else {
        edges.emplace_back(i, it.second);
        d[i]++;
        d[it.second]++;
        s.insert(make_pair(d[it.second], it.second));
        sisa--;
      }
    }
    for(auto it : toErase) {
      s.erase(it);
    }
  }
}

int main() {
  scanf("%d", &k);
  if(k % 2 == 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  edges.emplace_back(1, 2);
  node = 2;
  if(k != 1) {
    build(1, 3);
    build(2, k + 4);
  }
  printf("%d %d\n", node, edges.size());
  for(auto it : edges) {
    printf("%d %d\n", it.first, it.second);
  }
  
  return 0;
}
