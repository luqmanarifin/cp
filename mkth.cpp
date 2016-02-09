#include <bits/stdc++.h>

using namespace std;

const int N = 11111;

struct node {
  int count;
  node *left, *right;
  node(int count, node *left, node *right):
    count(count), left(left), right(right) {}
  node* insert(int, int, int);
};

node *null = new node(0, NULL, NULL);

int pt;

node* node::insert(int l, int r, int w) {
  if(l <= w && w < r) {
    printf("%d : %d %d %d = %d %d\n", pt, l, r, w, this->count+1, this);
    if(l + 1 == r) {
      return new node(this->count+1, null, null);
    }
    int m = (l + r) >> 1;
    printf("%d %d\n", this->left, this->right);
    return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
  }
  printf("%d : %d %d %d bodoh\n", pt, l, r, w);
  return this;
}

int query(node *a, node *b, int l, int r, int k) {
  if(l + 1 == r) return l;
  int m = (l + r) >> 1;
  int count = a->left->count - b->left->count;
  if(count >= k) return query(a->left, b->left, l, m, k);
  return query(a->right, b->right, m, r, k-count);
}

int a[N], RM[N];
node *root[N];

int main()
{
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    
    int n, m;
    scanf("%d %d", &n, &m);
    map <int, int> M;
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      M[a[i]];
    }

    int maxi = 0;
    for(map <int, int> :: iterator it = M.begin(); it != M.end(); it++) {
      //printf("%d %d\n", it->first, maxi);
      M[it->first] = maxi;
      RM[maxi] = it->first;
      maxi++;
    }
    null->left = null->right = null;
    for(int i = 0; i < n; i++) {
      pt = i;
      root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, M[a[i]] );
    }
    puts("done!");
    /*
    while(m--) {
      int u, v, k;
      scanf("%d %d %d", &u, &v, &k);
      u--; v--;
      int ans = query(root[v], (u==0?null:root[u-1]), 0, maxi, k);
      printf("%d\n", RM[ans]);
    }
    */
  }
}