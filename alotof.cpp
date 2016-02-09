#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

class Node {
public:
  Node() {
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    win = 0;
    lose = 0;
  }
  ~Node() {
    for(int i = 0; i < 26; i++) {
      delete child[i];
    }
  }
  bool win, lose;
  Node* child[26];
};

void add(Node* root, char* s) {
  int len = strlen(s);
  Node* now = root;
  for(int i = 0; i < len; i++) {
    if(!now->child[s[i] - 'a']) {
      now->child[s[i] - 'a'] = new Node();
    }
    now = now->child[s[i] - 'a'];
  }
}

void dfs(Node* now) {
  bool leaf = 1;
  for(int i = 0; i < 26; i++) {
    if(now->child[i]) {
      leaf = 0;
      dfs(now->child[i]);
      if(!now->child[i]->win) {
        now->win = 1;
      }
      if(!now->child[i]->lose) {
        now->lose = 1;
      }
    }
  }
  if(leaf) {
    now->lose = 1;
  }
}

char s[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  Node* root = new Node();
  while(n--) {
    scanf("%s", s);
    add(root, s);
  }
  dfs(root);
  if(!root->win) {
    puts("Second");
  } else if(root->lose) {
    puts("First");
  } else {
    puts(k % 2? "First" : "Second");
  }
  delete root;
  return 0;
}
