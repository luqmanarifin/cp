#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long offset = 1e18 + 5;

bool num[N << 2];

bool get(int p, int l, int r, int at) {
  if(at <= l && r <= at) {
    return num[p];
  }
  int mid = (l + r) >> 1;
  if(at <= mid) {
    return num[p] ^ get(p << 1, l, mid, at);
  } else {
    return num[p] ^ get(p << 1 | 1, mid + 1, r, at);
  }
}

void modify(int p, int l, int r, int ll, int rr) {
  if(ll <= l && r <= rr) {
    num[p] ^= 1;
    return;
  }
  int mid = (l + r) >> 1;
  if(ll <= mid) {
    modify(p << 1, l, mid, ll, rr);
  }
  if(mid < rr) {
    modify(p << 1 | 1, mid + 1, r, ll, rr);
  }
}

int par[N];
int event[N];
vector<int> bin[N << 2];
long long sorted[N];
int isi;

int find(int u) {
  if(par[u] != u) {
    par[u] = find(par[u]);
  }
  return par[u];
}

void merge(int u, int v, int assign) {
  u = find(u);
  v = find(v);
  par[u] = v;
  event[v] = assign;
} 

vector<long long> pos;
long long q[N][2];
bool sama[N];

int id(long long a) {
  return lower_bound(pos.begin(), pos.end(), a) - pos.begin();
}

void dfs(int now) {
  if(now < pos.size()) {
    sorted[isi++] = pos[now];
    return;
  }
  for(auto it : bin[now]) dfs(it);
}

vector<pair<long long, int>> segtree;
int l[N], r[N];

int letak(long long a) {
  int pos = lower_bound(segtree.begin(), segtree.end(), make_pair(a, -1)) - segtree.begin();
  return segtree[pos].second;
}

void merge_query(int u, int v) {
  u = find(u);
  v = find(v);
  par[u] = v;
  l[v] = min(l[u], l[v]);
  r[v] = max(r[u], r[v]);
}

int main() {
  ios_base::sync_with_stdio(false);
  int numq;
  cin >> numq;
  for(int i = 0; i < numq; i++) {
    string a, b;
    cin >> q[i][0] >> q[i][1] >> a >> b;
    q[i][0] += offset;
    pos.push_back(q[i][0]);
    pos.push_back(q[i][1]);
    sama[i] = (a == b);
  }
  sort(pos.begin(), pos.end());
  pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
  
  for(int i = 0; i < N; i++) {
    par[i] = i;
    event[i] = i;
  }
  int num_event = pos.size();
  for(int i = 0; i < numq; i++) {
    int par_a = find(id(q[i][0]));
    int par_b = find(id(q[i][1]));
    if(par_a != par_b) {
      bin[num_event].push_back(event[par_a]);
      bin[num_event].push_back(event[par_b]);
      merge(par_a, par_b, num_event++);
    }
  }
  for(int i = 1; i < pos.size(); i++) {
    int par_a = find(i - 1);
    int par_b = find(i);
    if(par_a != par_b) {
      bin[num_event].push_back(event[par_a]);
      bin[num_event].push_back(event[par_b]);
      merge(par_a, par_b, num_event++);
    }
  }
  dfs(num_event - 1);
  assert(isi == pos.size());
  
  for(int i = 0; i < isi; i++) {
    par[i] = l[i] = r[i] = i;
    segtree.emplace_back(sorted[i], i);
  }
  sort(segtree.begin(), segtree.end());
  
  bool can = 1;
  for(int i = 0; i < numq; i++) {
    if(can == 0) {
      puts("No");
      continue;
    }
    int a = letak(q[i][0]);
    int b = letak(q[i][1]);
    if(find(a) != find(b)) {
      if((get(1, 0, isi - 1, a) == get(1, 0, isi - 1, b)) != sama[i]) {
        modify(1, 0, isi - 1, l[find(a)], r[find(a)]);
      }
      merge_query(a, b);
    } else {
      if((get(1, 0, isi - 1, a) == get(1, 0, isi - 1, b)) != sama[i]) {
        can = 0;
      }
    }
    puts(can? "Yes" : "No");
  }
  
  return 0;
}
