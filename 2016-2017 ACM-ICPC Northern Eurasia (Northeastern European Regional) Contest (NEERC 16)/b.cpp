#include <bits/stdc++.h>

using namespace std;
const string filename = "binary";

const int N = 2e6 + 5, M = N * 10;

struct trie {
  int l, r;
  trie(int l = 0, int r = 0) : l(l), r(r) {} 
} node[M];
int ct;

int get(int root, const string & s) {
  int now = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1')
      now = node[now].r;
    else
      now = node[now].l;
  }
  return now;
}

int add(int root, const string & s) {
  int now = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      if (!node[now].r) node[now].r = ++ct;
      now = node[now].r;
    }
    else {
      if (!node[now].l) node[now].l = ++ct;
      now = node[now].l;
    }
  }
  return now;
}


int n;
string s[N];
int pos[N];
vector<int> g[M];

void addToChild(int v, int r) {
  cerr << v << " ke " << r << " " << node[r].l << " " << node[r].r << endl;
  if (node[r].l)
    g[v].push_back(node[r].l);
  if (node[r].r)
    g[v].push_back(node[r].r);
}
vector<int> processedNode;

int addBatch(int l, int r) {
  if (r - l < 2) {
    int now = processedNode[l];
    if (now >= n)
      now -= n;
    else
      now += n;
    return now;
  }
  else {
    int mid = (l + r) >> 2;
    int le = addBatch(l, mid), ri = addBatch(mid, r);
    for (int i = l; i < mid; ++i)
      g[processedNode[i]].push_back(ri);
    for (int i = mid; i < r; ++i)
      g[processedNode[i]].push_back(le);
    if (r-l == processedNode.size()) return 0;
    int now = ++ct;
    g[now].push_back(le);
    g[now].push_back(ri);
    return now;
  }
}

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, cc;
vector<vector<int> > elem;
int cntr, numCC;

void dfs(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      dfs(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    elem.push_back(vector<int>());
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      elem.back().push_back(u);
      cc[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

vector<vector<int> > dag;
bool isTrue[N];

void die() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  exit(0);
}

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ct = 2 * n + 1;
  int root = 2 * n;
  cerr << " root " << root << endl;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    pos[i] = -1;
    for (int j = 0; j < s[i].size(); ++j)
      if (s[i][j] == '?') {
        pos[i] = j;
        break;
      }
    if (pos[i] == -1) {
      int r = add(root, s[i]);
      g[r].push_back(i);
      g[r].push_back(i+n);
    }
    else {
      s[i][pos[i]] = '0';
      int r = add(root, s[i]);
      g[r].push_back(i+n);
      
      s[i][pos[i]] = '1';
      r = add(root, s[i]);
      g[r].push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (pos[i] == -1) {
      int r = get(root, s[i]);
      addToChild(i, r);
      addToChild(i+n, r);
    }
    else {
      s[i][pos[i]] = '0';
      int r = get(root, s[i]);
      addToChild(i, r);
      s[i][pos[i]] = '1';
      r = get(root, s[i]);
      addToChild(i+n, r);
    }
  }
  for (int i = 0; i < ct; ++i) {
    for (int u : g[i]) {
      cerr << i << " to " << u << endl;
    }
  }
  int last = ct;
  for (int i = root; i <= last; ++i) {
    addToChild(i, i);
    if (g[i].empty()) continue;
    processedNode.clear();
    processedNode = g[i];
    for (int & v : processedNode) {
      if (v >= n) v -= n;
      else v += n;
    }
    addBatch(0, processedNode.size());
    // cerr << i << endifl;
  }
  num.assign(ct+1, -1);
  low.assign(ct+1, -1);
  vis.assign(ct+1, 0);
  cc.assign(ct+1, 0);
  cntr = numCC = 0;
  cerr << " done construct " << endl;
  for (int i = 0; i <= ct; ++i) {
    if (num[i] != -1) continue;
    dfs(i);
  }
  cerr << " done tarjan " << endl;
  for (int i = 0; i < n; ++i) {
    if (cc[i] == cc[i+n]) {
      puts("NO");
      die();
    }
  }
  vector<int> din(numCC+1, 0);
  dag.resize(numCC);
  for (int i = 0; i <= ct; ++i) {
    for (int u : g[i]) {
      cerr << u << " " << i << endl;
      if (cc[u] != cc[i]) {
        dag[cc[i]].push_back(cc[u]);
        ++din[cc[u]];
      }
    }
  }
  vector<int> topo;
  stack<int> st;
  for (int i = 0; i < numCC; ++i) if (din[i]== 0) {
    st.push(i);
  }
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : dag[v]) {
      --din[u];
      if (din[u] == 0)
        st.push(u);
    }
  }
  cerr << " done topo " << endl;
  reverse(topo.begin(), topo.end());
  vector<bool> ok(numCC, 0);
  for (int v : topo) {
    if (!ok[v]) {
      for (int u : dag[v])
        ok[u] = 1;
    }
    for (int e : elem[v])
      if (e < 2 * n)
        isTrue[e] = ok[v];
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
//    assert(isTrue[i] != isTrue[i+n]);
    if (pos[i] != -1) {
      s[i][pos[i]] = isTrue[i] ? '0' : '1';
    }
    cout << s[i] << "\n";
  }
  die();
  return 0;
}