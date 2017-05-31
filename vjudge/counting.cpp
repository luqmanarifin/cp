#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node {
  int count;
  node *left, *right;
  node(int count, node *left, node *right):
    count(count), left(left), right(right) {}
  node* insert(int, int, int);
};

node *null = new node(0, NULL, NULL);

node* node::insert(int l, int r, int w) {
  if(l <= w && w < r) {
    if(l + 1 == r) {
      return new node(this->count+1, null, null);
    }
    int m = (l + r) >> 1;
    return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
  }
  return this;
}

int query(node *a, node *b, node* p, node* q, int l, int r, int k) {
  if(l + 1 == r) return l;
  int m = (l + r) >> 1;
  int count = a->left->count - b->left->count + p->left->count - q->left->count;
  if(count >= k) return query(a->left, b->left, p->left, q->left, l, m, k);
  return query(a->right, b->right, p->right, q->right, m, r, k-count);
}

int a[N], n;
vector<int> edge[N];
map<int, int> M;
int RM[N];

int h[N], rmq[2 * N][20], lef[N], rig[N], dad[N];
vector<int> pre;

node* nodes[N];

void dfs(int now, int bef) {
  dad[now] = bef;
  nodes[now] = (bef? nodes[bef] : null)->insert(0, n, M[a[now]]);
  h[now] = h[bef] + 1;
  lef[now] = rig[now] = pre.size();
  pre.push_back(now);
  for (int i = 0; i < edge[now].size(); i++) {
    int it = edge[now][i];
    if (it == bef) continue;
    dfs(it, now);
    rig[now] = pre.size();
    pre.push_back(now);
  }
}  

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r-l+1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int main()
{
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    M[a[i]];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int cnt = 0;
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
    M[it->first] = cnt;
    RM[cnt] = it->first;
    cnt++;
  }
  
  null->left = null->right = null;
  dfs(1, 0);
  for (int i = 0; i < pre.size(); i++) rmq[i][0] = pre[i];
  for (int j = 1; (1 << j) <= pre.size(); j++) {
    for (int i = 0; i + (1 << j) <= pre.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
  //puts("build done");
  nodes[0] = null;
  while (q--) {
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k);
    int root = lca(u, v);
    //printf("lca %d %d: %d\n", u, v, root);
    int ans = query(nodes[u], nodes[root], nodes[v], nodes[dad[root]], 0, n, k);
    //printf("RM %d\n", ans);
    printf("%d\n", RM[ans]);
  }
}