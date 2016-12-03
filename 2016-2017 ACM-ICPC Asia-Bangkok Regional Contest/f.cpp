#include <bits/stdc++.h>

using namespace std;

struct node {
  node * to[26];
  int grund;
  node(int grund = 0) : grund(grund) {
    memset(to, 0, sizeof to);
  }
  void insert(char * s) {
    int n = strlen(s);
    node * now = this;
    vector< node * > nodes;
    for (int i = 0; i < n; i++) {
      int id = s[i] - 'a';
      if (!now->to[id]) {
        now->to[id] = new node(0);
        now->grund ^= 1;
      }
      nodes.push_back(now);
      now->grund ^= (now->to[id]->grund+1);
      now = now->to[id];
    }
    int cur = now->grund;
    for (int i = n-1; i >= 0; i--) {
      cur++;
      cur ^= nodes[i]->grund;
      //cerr << "cuk " << cur << endl;
      nodes[i]->grund = cur;
    }
  }
};
char s[100000];

int main() {
  int t;
  scanf("%d", &t);
  int tc = 1;
  while (t--) {
    int n;
    scanf("%d", &n);
    node * root = new node();
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      root->insert(s);
    //cerr << "grund" << root->grund << endl;
    }
    int q;
    scanf("%d", &q);
    printf("Case %d:\n", tc++);
    while (q--) {
      scanf("%s", s);
      root->insert(s);
      //cerr << "grund " << root->grund << endl;
      puts(root->grund ? "1" : "2");
    }
 }
  return 0;
}