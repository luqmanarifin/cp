#include <bits/stdc++.h>

using namespace std;

struct Node {
public:
  Node() {
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    ada = 0;
  }
  ~Node() {
    for(int i = 0; i < 26; i++) {
      delete child[i];
    }
  }
  Node* child[26];
  bool ada;
};

void add(Node* now, char* s) {
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    if(!now->child[s[i] - 'A']) {
      now->child[s[i] - 'A'] = new Node();
    }
    now = now->child[s[i] - 'A'];
  }
  now->ada = 1;
}

// jawaban - anak nganggur
pair<int, bool> dfs(Node* now) {
  int ans = 0, row = 0;
  for(int i = 0; i < 26; i++) {
    if(now->child[i]) {
      pair<int, int> tmp = dfs(now->child[i]);
      ans += tmp.first;
      row |= tmp.second;
    }
  }
  if(now->ada) {
    if(row) {
      return make_pair(ans + 1, 0);
    }
    return make_pair(ans, 1);
  }
  return make_pair(ans, 0);
}

char s[50];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    Node* root = new Node();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s", s);
      add(root, s);
    }
    pair<int, int> ans = dfs(root);
    printf("Case #%d: %d\n", tt, ans.first);
    delete root;
  }
  return 0;
}
