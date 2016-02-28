#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const int mod = 1e9 + 7;

struct segtree {
public:
  segtree(int n) : n(n) {
    num.assign(n << 2, {1e100, -1});
  }
  void update(int l, int r, pair<double, int> val) {
    update(1, 1, n, l, r, val);
  }
  void relax() {
    push(1, 1, n);
  }
  int get(int at) {
    return get(1, 1, n, at);
  }  
private:
  void update(int p, int l, int r, int ll, int rr, pair<double, int> val) {
    if(ll <= l && r <= rr) {
      num[p] = min(num[p], val);
      return;
    }
    if(r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, val);
    update(p + p + 1, mid + 1, r, ll, rr, val);
  }
  void push(int p, int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    num[p + p] = min(num[p + p], num[p]);
    num[p + p + 1] = min(num[p + p + 1], num[p]);
    push(p + p, l, mid);
    push(p + p + 1, mid + 1, r);
  }
  int get(int p, int l, int r, int at) {
    if(l == r) return num[p].second;
    int mid = (l + r) >> 1;
    if(at <= mid) {
      return get(p + p, l, mid, at);
    } else {
      return get(p + p + 1, mid + 1, r, at);
    }
  }
  int n;
  vector<pair<double, int>> num;
};

int rmq[17][N][20], a[N], n;
vector<int> prime;
long long ans[N];

void build_rmq() {
  for(int p = 0; p < prime.size(); p++) {
    for(int i = 0; i < n; i++) {
      int tmp = a[i];
      while(tmp % prime[p] == 0) {
        rmq[p][i][0]++;
        tmp /= prime[p];
      }
    }
    for(int j = 1; (1 << j) <= n; j++) {
      for(int i = 0; i + (1 << j) <= n; i++) {
        rmq[p][i][j] = max(rmq[p][i][j-1], rmq[p][i+(1<<(j-1))][j-1]);
      }
    }
  }
  /*
  for(int j = 0; (1 << j) <= n; j++) {
    for(int i = 0; i < n; i++) {
      printf("%d ", rmq[0][i][j]);
    }
    printf("\n");
  }
  */
}

int find(int p, int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(rmq[p][l][g], rmq[p][r-(1<<g)+1][g]);
}

bool same(vector<int>&a , vector<int>& b) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) return 0;
  }
  return 1;
}

int power(int a, int b) {
  if(b == 0) return 1;
  int tmp = power(a, b / 2);
  tmp *= tmp;
  if(b & 1) tmp *= a;
  return tmp;
}

int main() {
  for(int i = 2; i <= 60; i++) {
    bool ada = 0;
    for(int j = 2; j < i; j++) {
      if(i % j == 0) ada = 1;
    }
    if(!ada) prime.push_back(i);
  }
  assert(prime.size() == 17);
  
  int m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  //puts("DONE BACA");
  build_rmq();
  segtree seg(n);
  //puts("DONE SEGTREE");
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j < n) {
      vector<int> col;
      for(int p = 0; p < prime.size(); p++) {
        col.push_back(find(p, i, j));
        //printf("%d ", col.back());
      }
      //printf("\n");
      int l = j, r = n - 1;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        vector<int> cob;
        for(int p = 0; p < prime.size(); p++) {
          cob.push_back(find(p, i, mid));
        }
        if(same(col, cob)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      double g = 0;
      long long norm = 1;
      for(int p = 0; p < col.size(); p++) {
        g += log(power(prime[p], col[p]));
        norm *= power(prime[p], col[p]);
      }
     // printf("%I64d = %.15f\n", norm, g);
      //printf("%d : %d %d\n", i, j, l);
      seg.update(j - i + 1, l - i + 1, {g, i});
      //puts("UPDATE GOOD");
      j = l + 1;
    }
  }
  seg.relax();
  for(int len = 1; len <= n; len++) {
    ans[len] = 1;
    int i = seg.get(len);
    //printf("len %d : i %d\n", len, i);
    for(int p = 0; p < prime.size(); p++) {
      int kali = find(p, i, i + len - 1);
      while(kali--) {
        ans[len] = ans[len] * prime[p] % mod;
      }
    }
  }
  while(m--) {
    int v;
    scanf("%d", &v);
    printf("%d\n", (int) ans[v]);
  }
  return 0;
}
