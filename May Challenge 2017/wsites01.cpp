#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct node {
  node() {
    pos = neg = cntp = cntn = 0;
    for (int i = 0; i < 26; i++) child[i] = NULL;
  }
  int pos, neg, cntp, cntn;
  node* child[26];
};

node* root;

void add(char* s, int val) {
  node* now = root;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (val == 1) {
      now->cntp++;
    } else {
      now->cntn++;
    }
    int c = s[i] - 'a';
    if (now->child[c] == 0) now->child[c] = new node();
    now = now->child[c];
  }
  if (val == 1) {
    now->cntp++;
    now->pos = 1;
  } else {
    now->cntn++;
    now->neg = 1;
  }
}

vector<string> ans;
string cur;
char s[N];

void dfs(node* now) {
  if (now->neg && now->cntp) {
    puts("-1");
    exit(0);
  }
  if (now->cntn == 0) return;
  if (now->cntp == 0) {
    ans.push_back(cur);
    return;
  }
  for (int i = 0; i < 26; i++) if (now->child[i]) {
    cur += i + 'a';
    dfs(now->child[i]);
    cur.pop_back();
  }
}

int main() {
  root = new node();
  
  int n;
  scanf("%d", &n);
  while (n--) {
    char c;
    scanf(" %c %s", &c, s);
    if (c == '+') {
      add(s, 1);
    } else {
      add(s, -1);
    }
  }
  dfs(root);
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%s\n", it.c_str());
  return 0;
}
