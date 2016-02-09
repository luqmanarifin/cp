#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() {
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    cur = 0;
    cnt = 0;
  }
  int cur;
  int cnt;
  Node* child[26];
};

void add(Node* root, char* s) {
  int n = strlen(s);
  Node* now = root;
  for(int i = 0; i < n; i++) {
    now->cnt++;
    if(!now->child[s[i] - 'A']) {
      now->child[s[i] - 'A'] = new Node();
    }
    now = now->child[s[i] - 'A'];
  }
  now->cur++;
  now->cnt++;
}

int query(Node* root, char* s) {
  int n = strlen(s);
  Node* now = root;
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int to = s[i] - 'A';
    for(int j = 0; j < to; j++) {
      if(now->child[j]) {
        ret += now->child[j]->cnt;
      }
    }
    now = now->child[to];
    ret += now->cur;
  }
  return ret;
}

char s[15];
char str[15];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  Node* root = new Node();
  while(n--) {
    scanf("%s", s);
    add(root, s);
  }
  while(q--) {
    scanf("%s %s", str, s);
    if(str[0] == 'U') {
      add(root, s);
    } else {
      printf("%d\n", query(root, s));
    }
  }
  return 0;
}
