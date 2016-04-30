#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
const int sz = 2;

struct mat {
  mat() {
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        a[i][j] = 0;
      }
    }
  }
  mat(long long p[sz][sz]) {
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        a[i][j] = p[i][j];
      }
    }
  }
  // power of matriks
  mat(long long n) {
    if(n == 0) {
      for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
          a[i][j] = i == j;
        }
      }
    } else if(n == 1) {
      for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
          a[i][j] = 1;
        }
      }
      a[sz - 1][sz - 1] = 0;
    } else {
      mat ret(1);
      ret = power(ret, n);
      for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
          a[i][j] = ret.a[i][j];
        }
      }
    }
  }
  mat operator=(mat o) {
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        a[i][j] = o.a[i][j];
      }
    }
    return *this;
  }
  mat operator+(mat other) {
    mat ret;
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        ret.a[i][j] = (a[i][j] + other.a[i][j]) % mod;
      }
    }
    return ret;
  }
  mat operator-(mat other) {
    mat ret;
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        ret.a[i][j] = (a[i][j] - other.a[i][j] + mod) % mod;
      }
    }
    return ret;
  }
  mat operator*(mat other) {
    mat ret;
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        for(int k = 0; k < sz; k++) {
          ret.a[i][j] += a[i][k] * other.a[k][j];
          ret.a[i][j] %= mod;
        }
      }
    }
    return ret;
  }
  mat power(mat m, long long k) {
    mat ret(0LL);
    if(k == 0) return ret;
    mat temp = power(m, k / 2);
    temp = temp * temp;
    if(k & 1) {
      temp = temp * m;
    }
    return temp;
  }
  long long a[sz][sz];
};

mat get_fibo_mat(long long n) {
  return mat(n - 1);
}

long long get_fibo(long long n) {
  return get_fibo_mat(n).a[0][0];
}

struct segtree {
  segtree() {}
  segtree(int n) : n(n) {
    a.resize(n << 2);
    ori.resize(n << 2);
  }
  segtree operator=(const segtree& seg) {
    n = seg.n;
    a = seg.a;
    ori = seg.ori;
    return *this;
  }
  void update(int at, long long ke) {
    update(1, 0, n - 1, at, ke);
  }
  void update(int p, int l, int r, int at, long long ke) {
    if(l == r) {
      a[p] = a[p] + get_fibo_mat(ke);
      ori[p] = ori[p] + get_fibo_mat(ke);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, ke);
    } else {
      update(p + p + 1, mid + 1, r, at, ke);
    }
    a[p] = a[p + p] * mat(r - mid);
    a[p] = a[p] + a[p + p + 1];
    ori[p] = ori[p + p] + ori[p + p + 1];
  }
  pair<mat,mat> get_mat(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  pair<mat,mat> get(int p, int l, int r, int ll, int rr) {
    if(l == ll && rr == r) return make_pair(a[p], ori[p]);
    //printf("%d %d %d %d\n", l, r, ll, rr);
    int mid = (l + r) >> 1;
    mat aret, oriret;
    if(ll <= mid) {
      pair<mat, mat> ret = get(p + p, l, mid, ll, min(rr, mid));
      mat eks(0LL);
      if(rr - mid >= 0) eks = mat(rr - mid);
      aret = aret + ret.first * eks;
      oriret = oriret + ret.second;
    }
    if(mid < rr) {
      pair<mat, mat> ret = get(p + p + 1, mid + 1, r, max(mid + 1, ll), rr);
      aret = aret + ret.first;
      oriret = oriret + ret.second;
    }
    return make_pair(aret, oriret);
  }
  int n;
  vector<mat> a, ori;
};

vector<int> edge[N];
int cnt[N], dad[N], h[N];

// in array of heavy light
segtree seg[N];
vector<int> mem[N];
int id[N];

// identifier of component
int comp[N], num_comp;

// rmq things
int rmq[N << 1][20], lef[N], rig[N], cnt_rmq;

void dfs_basic(int now) {
  cnt[now] = 1;
  lef[now] = rig[now] = cnt_rmq;
  rmq[cnt_rmq++][0] = now;
  for(auto it : edge[now]) {
    h[it] = h[now] + 1;
    dfs_basic(it);
    cnt[now] += cnt[it];
    rig[now] = cnt_rmq;
    rmq[cnt_rmq++][0] = now;
  }
}

void dfs(int now) {
  mem[num_comp].push_back(now);
  comp[now] = num_comp;
  
  int maks = -1, p = -1;
  for(auto it : edge[now]) {
    if(cnt[it] > maks) {
      maks = cnt[it];
      p = it;
    }
  }
  if(p == -1) return;
  dfs(p);
  
  for(auto it : edge[now]) {
    if(it == p) continue;
    num_comp++;
    dfs(it);
  }
}

void build_hld() {
  dfs_basic(1);
  dfs(1);
  //printf("terjadi %d componen\n", num_comp + 1);
  for(int i = 0; i <= num_comp; i++) {
    //printf("%d : ", i);
    for(int j = 0; j < mem[i].size(); j++) {
      id[mem[i][j]] = j;
      //printf("%d ", mem[i][j]);
    }
    seg[i] = segtree(mem[i].size());
    //printf("\nsize comp %d\n",seg[i].n);
  }
}

void build_rmq() {
  for(int j = 1; (1 << j) <= cnt_rmq; j++) {
    for(int i = 0; i + (1 << j) <= cnt_rmq; i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j - 1]]? rmq[i][j - 1] : rmq[i+(1<<(j-1))][j - 1]);
    }
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(lef[u], lef[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

void print(mat m) {
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      printf("%lld ", m.a[i][j]);
    }
    printf("\n");
  }
}

long long find(int now) {
  int hi = h[now];
  //printf("level %d\n", hi);
  long long ans = 0;
  //printf("cari %d\n", now);
  while(now) {
    pair<mat, mat> ret = seg[comp[now]].get_mat(0, id[now]);
    //printf("lewat %d\n", now);
    mat a = ret.first;
    mat ori = ret.second;
    //printf("hi %d %d\n", hi, h[now]);
    a = a * mat(hi - h[now]);
    a = a * mat(2);
    ori = ori * mat(1);
    /*print(a);
    print(ori);
    printf("\n");*/
    a = a - ori;
    ans += a.a[0][0];
    now = dad[mem[comp[now]][0]];
  }
  return ans % mod;
}

long long find(int u, int v) {
  int root = lca(u, v);
  //printf("root %d\n", root);
  //printf("find 0 = %lld\n", find(1));
  long long ans = find(u) + find(v) - find(root) - find(dad[root]);
  ans %= mod;
  if(ans < 0) ans += mod;
  return ans;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 2; i <= n; i++) {
    scanf("%d", dad + i);
    edge[dad[i]].push_back(i);
  }
  build_hld();
  build_rmq();
  //puts("build done");
  while(q--) {
    char c;
    int at;
    long long v;
    scanf(" %c %d %lld", &c, &at, &v);
    if(c == 'U') {
      seg[comp[at]].update(id[at], v);
    } else {
      printf("%lld\n", find(at, (int)v));
    }
    //puts("done");
  }
  //cout << find(5) << endl;
  //cout << find(5) << endl;
  //for(int i = 1; i <= n; i++) printf("%d high %d\n", i, h[i]);
  return 0;
}