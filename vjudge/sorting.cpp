#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

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
    if(l + 1 == r) {
      return new node(this->count+1, null, null);
    }
    int m = (l + r) >> 1;
    return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
  }
  return this;
}

int query(node *a, node *b, int l, int r, int k) {
  if(l + 1 == r) return l;
  int m = (l + r) >> 1;
  int count = a->left->count - b->left->count;
  if(count >= k) return query(a->left, b->left, l, m, k);
  return query(a->right, b->right, m, r, k-count);
}

int a[N], pos[N], n;
node *root[N];
int maxi;
long long ans;

int solve(int l, int r, int k) {
  return query(root[r], (l==0?null:root[l-1]), 0, n, k);
}

void solve(int l, int r) {
  if (l >= r) return;
  int cnt = r - l + 1;
  int piv = solve(l, r, (cnt + 1) / 2);
  ans += cnt;
  solve(l, a[piv] - 1);
  solve(a[piv] + 1, r);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
    pos[a[i]] = i;
  }

  null->left = null->right = null;
  for (int i = 0; i < n; i++) {
    root[i] = (i == 0 ? null : root[i-1])->insert( 0, n, pos[i] );
  }
  solve(0, n - 1);
  cout << ans << endl;
}