#include <bits/stdc++.h>

using namespace std;

const int N = 3000;
const int inf = 1e9;

struct Node {
  Node() {}
  Node(int from, int to) : from(from), to(to) {
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
  Node* child[26];
  int from, to;
};

Node* root;
char a[N], b[N];

int dp[N], bef[N], from[N], to[N];

void backtrack(int m) {
  if(m == 0) return;
  backtrack(bef[m]);
  printf("%d %d\n", from[m], to[m]);
}

int main() {
  scanf("%s %s", a + 1, b + 1);
  int na = strlen(a + 1);
  int nb = strlen(b + 1);
  root = new Node(-1, -1);
  for(int i = 1; i <= na; i++) {
    Node* now = root;
    for(int j = i; j <= na; j++) {
      int c = a[j] - 'a';
      if(!now->child[c]) {
        now->child[c] = new Node(i, j);
      }
      now = now->child[c];
    }
    now = root;
    for(int j = i; j >= 1; j--) {
      int c = a[j] - 'a';
      if(!now->child[c]) {
        now->child[c] = new Node(i, j);
      }
      now = now->child[c];
    }
  }
  //puts("entry mari cuk asu");
  for(int i = 1; i < N; i++) {
    dp[i] = inf;
  }
  for(int i = 1; i <= nb; i++) {
    Node* now = root;
    for(int j = i; j <= nb; j++) {
      int c = b[j] - 'a';
      if(!now->child[c]) break;
      now = now->child[c];
      if(dp[i - 1] + 1 < dp[j]) {
        dp[j] = dp[i - 1] + 1;
        bef[j] = i - 1;
        from[j] = now->from;
        to[j] = now->to;
      }
    }
  }
  if(dp[nb] == inf) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dp[nb]);
  backtrack(nb);
  return 0;
}
