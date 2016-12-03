#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LN = 18, G = sqrt(2 * N);

int n, val[N], lf[N], rf[N], flat[N << 1];
vector< pair< int, int> > adj[N];
bool used[N];
int ans[N], cntr, cnt[N];

int bit[N];
void upd(int x, int v) {
  for (; x < N; x += x & (-x))
    bit[x] += v;
}
int get(int v) {
  int ret = 0;
  for (int i = LN; i >= 0; i--) {
    if (ret + (1<<i) < N && bit[ret + (1<<i)] < v)
      ret += (1<<i), v -= bit[ret];
  }
  if (v)
    ret++;
  return ret;
}

void dfs(int v, int par = -1, int w = 0) {
  val[v] = w;
  used[v] = 0;
  flat[cntr] = v;
  lf[v] = cntr++;
  for (auto it : adj[v]) if (it.first != par) {
    dfs(it.first, v, it.second);
  }
  flat[cntr] = v;
  rf[v] = cntr++;
}
bool cmp(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b) {
  int ga = lf[a.first.first]/G, gb = gb = lf[b.first.first]/G;
  if (ga != gb)
    return ga < gb;
  return lf[a.first.second] < lf[b.first.second];
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    cntr = 0;
    dfs(0);
    int q;
    scanf("%d", &q);
    vector< pair< pair< int, int > , int > > que;
    for (int i = 0; i < q; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      if (lf[b] < lf[a])
        swap(a, b);
      que.push_back(make_pair(make_pair(a, b), i));
    }
    sort(que.begin(), que.end(), cmp);
    memset(bit, 0, sizeof bit);
    memset(used, 0, sizeof used);
    int l = 0, r = 0;
    int tot = 0;
    for (int i = 0; i < q; i++) {
      int la = lf[que[i].first.first], ra = lf[que[i].first.second], id = que[i].second;
      while (l < la) {
        l++;
        int w = val[flat[l]];
        if (used[flat[l]])
          upd(w, -1), tot--;
        else
          upd(w, +1), tot++;
        used[flat[l]] ^= 1;
      }
      while (l > la) {
        int w = val[flat[l]];
        if (used[flat[l]])
          upd(w, -1), tot--;
        else
          upd(w, +1), tot++;
        used[flat[l]] ^= 1;
        l--;
      }
      while (r < ra) {
        r++;
        int w = val[flat[r]];
        if (used[flat[r]])
          upd(w, -1), tot--;
        else
          upd(w, +1), tot++;
        used[flat[r]] ^= 1;
      }
      while (r > ra) {
        int w = val[flat[r]];
        if (used[flat[r]])
          upd(w, -1), tot--;
        else
          upd(w, +1), tot++;
        used[flat[r]] ^= 1;
        r--;
      }
      int ans1 = get((tot+1)/2), ans2 = get((tot+2)/2);
      ans[id] = ans1 + ans2;
    }
    for (int i = 0; i < q; i++) {
      printf("%d.%d\n", ans[i]/2, (ans[i] & 1) * 5);
    }
  }

  return 0;
}
