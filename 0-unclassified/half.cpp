#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

struct Node {
  Node() {
    for(int i = 0; i < 2; i++) {
      child[i] = nullptr;
      cnt[i] = 0;
    }
    cur = 0;
  }
  Node* child[2];
  int cnt[2];
  int cur;
};

void add(Node* root, char* s) {
  int n = strlen(s);
  Node* now = root;
  for(int i = 0; i < n; i++) {
    if(!now->child[s[i] - 'a']) {
      now->child[s[i] - 'a'] = new Node();
    }
    now = now->child[s[i] - 'a'];
  }
}

int dfs(Node* now) {
  for(int i = 0; i < 2; i++) {
    if(now->child[i]) {
      now->cnt[i] = dfs(now->child[i]);
    }
  }
  return now->cur + now->cnt[0] + now->cnt[1];
}

char s[N];
int n;
bool good[N][N];

int main() {
  int ke;
  scanf("%s %d", s, &ke);
  n = strlen(s);
  for(int i = 0; i < n; i++) {
    for(int j = i; j <= i + 3 && j < n; j++) {
      for(int k = 0; i - k >= 0 && j + k < n; k += 2) {
        if(s[i - k] == s[j + k]) {
          good[i - k][j + k] = 1;
        } else {
          break;
        }
      }
    }
  }
  
  Node* root = new Node();
  for(int i = 0; i < n; i++) {
    add(root, s + i);
  }
  for(int i = 0; i < n; i++) {
    Node* now = root;
    for(int j = i; j < n; j++) {
      now = now->child[s[j] - 'a'];
      if(good[i][j]) {
        now->cur++;
      }
    }
  }
  int tot = dfs(root);
  assert(ke <= tot);
  Node* now = root;
  while(ke > 0) {
    if(ke > now->cnt[0]) {
      printf("b");
      ke -= now->cnt[0];
      now = now->child[1];
    } else {
      printf("a");
      now = now->child[0];
    }
    ke -= now->cur;
  }
  printf("\n");
  return 0;
}
