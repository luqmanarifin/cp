#include <bits/stdc++.h>

using namespace std;

int main() {
  while(1);#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e4 + 5;

pair<int, int> num[N << 2];
vector<int> edge[N];
int a[N], urut[N];
int to[N];

void build(int p, int l, int r) {
  if(l == r) {
    num[p] = make_pair(0, 0);
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p] = max(num[p + p], num[p + p + 1]);
}

pair<int, int> query(int p, int l, int r, int ll, int rr) {
  while(1);
  if(ll <= l && r <= rr) {
    return num[p];
  }
  if(r < ll || rr < l) return make_pair(0, 0);
  int mid = (l + r) >> 1;
  return max(query(p + p, l, mid, ll, rr), query(p + p + 1, mid + 1, r, ll, rr));
}

void change(int p, int l, int r, int at, pair<int, int> val) {
  if(l == r) {
    num[p] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if(at <= mid) {
    change(p + p, l, mid, at, val);
  } else {
    change(p + p + 1, mid + 1, r, at, val);
  }
  num[p] = max(num[p + p], num[p + p + 1]);
}

int cmp(int l, int r) {
  return urut[l] < urut[r];
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    memset(a, 0, sizeof(a));
    memset(urut, 0, sizeof(urut));
    memset(to, 0, sizeof(to));
    
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 1; i <= m; i++) {
      scanf("%d", a + i);
    }
    while(r--) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      to[v]++;
    }
    stack<int> st;
    for(int i = 1; i <= n; i++) {
      if(to[i] == 0) {
        st.push(i);
      }
    }
    /* topo sort */
    vector<int> topo;
    while(!st.empty()) {
      int now = st.top();
      st.pop();
      topo.push_back(now);
      for(int i = 0; i < edge[now].size(); i++) {
        int near = edge[now][i];
        to[near]--;
        if(to[near] == 0) {
          st.push(near);
        }
      }
    }
    for(int i = 0; i < topo.size(); i++) {
      urut[topo[i]] = i;
    }
    sort(a + 1, a + 1 + m, cmp);
    build(1, 1, n);
    int j = 1, udah = 0;
    for(int i = 0; i < topo.size(); i++) {
      pair<int, int> bef = query(1, 1, n, 1, topo[i] - 1);
      int bc, be;
      if(bef.first == udah) {
        bc = bef.first + (topo[i] == a[j]);
        be = bef.second + 1;
      } else {
        bc = -inf;
        be = -inf;
      }
      if(j <= m && topo[i] == a[j]) {
        udah++;
        j++;
      }
      //printf("%d jadi %d %d\n", topo[i], bc, be);
      change(1, 1, n, topo[i], make_pair(bc, be));
    }
    printf("Case #%d: %d\n", tt, query(1, 1, n, 1, n).second);
  }
  
  return 0;
}

  
  return 0;
}
