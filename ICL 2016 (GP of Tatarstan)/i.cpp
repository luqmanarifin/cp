#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() {
    a = new int[4];
  }
  Node(int* b) {
    a = new int[4];
    for(int i = 0; i < 4; i++) {
      a[i] = b[i];
    }
  }
  bool operator<(const Node& other) const {
    for(int i = 0; i < 4; i++) {
      if(a[i] < other.a[i]) return 1;
      if(a[i] > other.a[i]) return 0;
    }
    return 0;
  }
  int dist(Node other) {
    int ans = 0;
    for(int i = 0; i < 4; i++) {
      ans += abs(a[i] - other.a[i]);
    }
    return ans;
  }
  int* a;
};

set<Node> s;
priority_queue<pair<int, Node>> pq[16];
int a[4];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < 4; i++) {
      scanf("%d", a + i);
    }
    Node node = Node(a);
    if(t == 1) {
      s.insert(node);
      for(int mask = 0; mask < (1 << 4); mask++) {
        int val = 0;
        for(int i = 0; i < 4; i++) {
          if(mask & (1 << i)) {
            val += a[i];
          } else {
            val -= a[i];
          }
        }
        pq[mask].push(make_pair(val, node));
      }
    } else if(t == 2) {
      s.erase(node);
    } else {
      int ans = 0;
      for(int mask = 0; mask < 16; mask++) {
        while(!pq[mask].empty()) {
          if(!s.count(pq[mask].top().second)) {
            pq[mask].pop();
            continue;
          }
          ans = max(ans, node.dist(pq[mask].top().second));
          break;
        }
      }
      printf("%d\n", ans);
    }
  }
  
  return 0;
}