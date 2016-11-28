#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.resize((n+1) << 2);
    push.resize((n+1) << 2);
    null = {-1, -1};
    build(1, 0, n);
  }
  void build(int p, int l, int r) {
    num[p] = {0, -1};
    push[p] = null;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  void relax(int p, int l, int r) {
    if (push[p] != null) {
      if (l < r) {
        push[p + p] = max(push[p + p], push[p]);
        push[p + p + 1] = max(push[p + p + 1], push[p]);
      }
      num[p] = max(num[p], push[p]);
      push[p] = null;
    }
  }
  void update(int l, int r, pair<int, int> val) {
    update(1, 0, n, l, r, val);
  }
  void update(int p, int l, int r, int ll, int rr, pair<int, int> val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, val);
    update(p + p + 1, mid + 1, r, ll, rr, val);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  pair<int, int> find(int at) {
    return find(1, 0, n, at);
  }
  pair<int, int> find(int p, int l, int r, int at) {
    relax(p, l, r);
    if (r < at || at < l) return null;
    if (l == r) return num[p];
    int mid = (l + r) >> 1;
    pair<int, int> ret = max(find(p + p, l, mid, at), find(p + p + 1, mid + 1, r, at));
    num[p] = max(num[p + p], num[p + p + 1]);
    return ret;
  }
  vector<pair<int, int>> num;
  vector<pair<int, int>> push;
  pair<int, int> null;
  int n;
};

char s[N];
int Z[N], from[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int L, R, k;
  
  // [L,R] make a window which matches with prefix of s
  L = R = 0;
  for (int i = 1; i < n; ++i)
  {
      // if i>R nothing matches so we will calculate.
      // Z[i] using naive way.
      if (i > R)
      {
          L = R = i;

          // R-L = 0 in starting, so it will start
          // checking from 0'th index. For example,
          // for "ababab" and i = 1, the value of R
          // remains 0 and Z[i] becomes 0. For sing
          // "aaaaaa" and i = 1, Z[i] and R become 5
          while (R<n && s[R-L] == s[R])
              R++;
          Z[i] = R-L;
          R--;
      }
      else
      {
          // k = i-L so k corresponds to number which
          // matches in [L,R] interval.
          k = i-L;

          // if Z[k] is less than remaining interval
          // then Z[i] will be equal to Z[k].
          // For example, s = "ababab", i = 3, R = 5
          // and L = 2
          if (Z[k] < R-i+1)
               Z[i] = Z[k];

          // For example s = "aaaaaa" and i = 2, R is 5,
          // L is 0
          else
          {
              //  else start from R  and check manually
              L = i;
              while (R<n && s[R-L] == s[R])
                  R++;
              Z[i] = R-L;
              R--;
          }
      }
  }
  //for (int i = 0; i < n; i++) printf("%d ", Z[i]); printf("\n");
  segtree seg(n);
  seg.update(1, n, {1, 0});
  for (int i = 1; i < n; i++) {
    pair<int, int> now = seg.find(i);
    from[i] = now.second;
    //printf("%d ", now.second);
    if (Z[i]) {
      //printf("update %d %d: %d\n", i+1, i+Z[i], i);
      seg.update(i + 1, i + Z[i], {now.first + 1, i});
    }
  }
  from[n] = seg.find(n).second;
  //for (int i = 0; i <= n; i++) printf("%d ", from[i]); printf("\n");
  //printf("\n");
  vector<int> ans;
  int now = n;
  while (now) {
    //printf("now %d\n", now);
    now = from[now];
    //printf("jadi %d\n", now);
    ans.push_back(now);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]+1);
  }
  printf("\n");
  return 0;
}
