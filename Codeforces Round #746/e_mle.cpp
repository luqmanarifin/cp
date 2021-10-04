#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int BIT = 20;

struct node {
  node(int bit, int val) : bit(bit), val(val) {
    child[0] = NULL;
    child[1] = NULL;
  };
  int bit;  // store which bit index
  int val;  // store the most rightest
  node* child[2];
};

struct binary_tree {
  binary_tree() {
    offset = 0;
    root = NULL;
  }
  binary_tree(vector<pair<int, int>> p) {
    offset = 0;
    root = new node(BIT, -1);
    for (auto it : p) {
      build(root, BIT - 1, it.first, it.second);
    }
  }
  void build(node* now, int i, int x, int val) {
    if (i < 0) return;
    // printf("build %d %d %d\n", i, x, val);
    int c = (x & (1 << i))? 1 : 0;
    if (now->child[c] == NULL) {
      now->child[c] = new node(i, val);
    } else {
      now->child[c]->val = max(now->child[c]->val, val);
    }
    build(now->child[c], i-1, x, val);
    for (int b = 0; b < 2; b++) {
      if (now->child[b]) {
        now->val = max(now->val, now->child[b]->val);
      }
    } 
  }
  void add_offset(int x) {
    offset ^= x;
  }
  int find(int x) {
    return find(root, BIT - 1, x);
  }
  int find(node* now, int i, int x) {
    int ret = -1;
    if (i < 0) return ret;
    int low = (offset & (1 << i))? 1: 0;
    int cur = ((x & (1 << i))? 1 : 0) ^ low;
    if (cur != low) {
      if (now->child[low]) {
        ret = max(ret, now->child[low]->val);
      }
    }
    // printf("i = %d, low = %d, cur = %d, offset = %d\n", i, low, cur, offset);
    int fut = cur;
    if (now->child[fut]) {
      ret = max(ret, find(now->child[fut], i - 1, x));
    }
    return ret;
  } 
  int offset; // offset of xor
  node* root;
};

struct segtree {
  segtree(vector<pair<int, int>> a) : a(a), n(a.size()) {
    push.resize(n << 2, 0);
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    vector<pair<int, int>> points;
    for (int i = l; i <= r; i++) points.push_back(a[i]);
    num[p] = binary_tree(points);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void update(int l, int r, int x) {
    update(1, 0, n - 1, l, r, x);
  }
  void update(int p, int l, int r, int ll, int rr, int x) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] ^= x;
      lazy(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, x);
    update(p + p + 1, mid + 1, r, ll, rr, x);
  }
  void lazy(int p, int l, int r) {
    if (push[p] != 0) {
      num[p].add_offset(push[p]);
      if (l < r) {
        push[p + p] ^= push[p];
        push[p + p + 1] ^= push[p];
      }
      push[p] = 0;
    }
  }
  int find(int l, int r, int x) {
    return find(1, 0, n - 1, l, r, x);
  }
  int find(int p, int l, int r, int ll, int rr, int x) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) {
      // printf("segtree find %d %d: %d\n", l, r, x);
      return num[p].find(x);
    }
    if (r < ll || rr < l) return -1;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr, x), find(p + p + 1, mid + 1, r, ll, rr, x));
  }
  vector<binary_tree> num; 
  vector<int> push; 
  vector<pair<int, int>> a;
  int n;
};

int rmq[N][20];

void build_rmq(int n, vector<int>& a) {
  for (int i = 0; i < n; i++) rmq[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      rmq[i][j] = (rmq[i][j-1] & rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

int find_rmq(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return rmq[l][g] & rmq[r-(1<<g)+1][g];
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  vector<pair<int, int>> p(n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    now ^= a[i];
    p[i] = {now, i};
  }
  build_rmq(n, a);
  // puts("and rmq build done");
  segtree seg(p);
  // puts("build done");
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    int cur = (a[i] & a[i + 1]);
    int start = i + 1;
    while (cur > 0 && start < n) {
      int l = start;
      int r = n - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        // printf("find rmq %d %d = %d, cur=%d, l %d r %d\n", i, mid, find_rmq(i, mid), cur, l, r);
        if (find_rmq(i, mid) == cur) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      // printf("l %d r %d\n", l, r);
      int ret = seg.find(start, r, cur);
      // printf("from %d : (%d-%d) : cur %d, ret %d, get %d\n", i, start, r, cur, ret, ret - i + 1);
      if (ret != -1) {
        ans = max(ans, ret - i + 1);
      }
      cur = (cur & a[r + 1]);
      start = r + 1;
    }
    if (i + 1 < n) {
      seg.update(i + 1, n - 1, a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
