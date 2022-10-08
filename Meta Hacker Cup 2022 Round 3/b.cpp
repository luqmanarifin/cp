#include <bits/stdc++.h>

using namespace std;

const int D = 26;
const int N = 2e6 + 5;

struct Node {
  Node() {
    num = 0;
    child.assign(D, NULL);
    // for (int i = 0; i < D; i++) child[i] = NULL;
  }
  ~Node() {
    for (int i = 0; i < D; i++) {
      if (child[i]) {
        delete child[i];
      }
    }
  }
  int num;
  vector<Node*> child;
};

Node* new_node() {
  return new Node();
}

int total;

void add_trie(Node* root, Node* cur, int val) {
  if (root->num == 0 && val > 0) {
    total++;
  }
  if (root->num + val == 0) {
    total--;
  }
  root->num += val;
  for (int i = 0; i < D; i++) {
    if (cur->child[i]) {
      if (root->child[i] == NULL) {
        root->child[i] = new_node();
      }
      add_trie(root->child[i], cur->child[i], val);
    }
  }
}

Node* add_node(Node* cur, int c) {
  if (cur->child[c] == NULL) {
    cur->child[c] = new_node();
  }
  return cur->child[c];
}

long long C(int n, int k) {
  if (n < k) return 0;
  long long ret = 1;
  for (int i = 1; i <= k; i++) {
    ret = ret * (n + 1 - i) / i;
  }
  return ret;
}

long long com[105][105];

long long solve(Node* cur, int n) {
  long long ret = com[n][3] - com[n-cur->num][3];
  for (int i = 0; i < D; i++) if (cur->child[i]) {
    ret += solve(cur->child[i], n);
  }
  return ret;
}

int main() {
  for (int n = 0; n < 105; n++) {
    for (int k = 0; k <= n; k++) {
      com[n][k] = C(n, k);
    }
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    Node* master = new_node();
    vector<vector<Node*>> nodes;
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
      int m;
      scanf("%d", &m);
      nodes[i].resize(m);
      nodes[i][0] = new_node();
      for (int j = 1; j < m; j++) {
        int p; char c;
        scanf("%d %c", &p, &c);
        p--;
        nodes[i][j] = add_node(nodes[i][p], c - 'a');
      }
    }

    for (int i = 0; i < n; i++) {
      printf("adding trie %d/%d\n", i+1, n);
      add_trie(master, nodes[i][0], +1);
    }
    printf("solving master node\n");
    long long ans = solve(master, n);
    printf("Case #%d: %lld\n", tt, ans);

    // clean up
    delete master;
    for (int i = 0; i < n; i++) delete nodes[i][0];

    cerr << tt << " done!" << endl;
  }
  return 0;
}
