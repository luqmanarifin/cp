#include <bits/stdc++.h>

using namespace std;

struct segtree {
  segtree(vector<pair<int, int>> _a) : a(_a) {
    num.resize(a.size() << 2);
    build(1, 0, a.size() - 1);
  }

  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if(l == r) {
      num[p][0] = a[l].second;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
  }

  int find(int al, int ar, int bl, int br) {
    return find(1, 0, a.size() - 1, al, ar, bl, br);
  }

  int find(int p, int l, int r, int al, int ar, int bl, int br) {
    //printf("%d %d %d %d %d %d %d\n", p, l, r, al, ar, bl, br);
    //printf("%d %d\n", a[l].first, a[r].first);
    if(al <= a[l].first && a[r].first <= ar) {
      return upper_bound(num[p].begin(), num[p].end(), br) - lower_bound(num[p].begin(), num[p].end(), bl);
    }
    if(ar < a[l].first || a[r].first < al) {
      return 0;
    }
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, al, ar, bl, br) + find(p + p + 1, mid + 1, r, al, ar, bl, br);
  }

  vector<pair<int, int>> a;
  vector<vector<int>> num;
};

struct node {
  node() {
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
  node* child[26];
  int l, r;
};

void add(node* root, string s) {
  int len = s.size();
  node* now = root;
  for(int i = 0; i < len; i++) {
    int c = s[i] - 'A';
    if(now->child[c] == NULL) {
      now->child[c] = new node();
    }
    now = now->child[c];
  }
}

int find(node* root, string s) {
  for(int i = 0; i < s.size(); i++) {
    root = root->child[s[i] - 'A'];
  }
  return root->l;
}

pair<int, int> find_pair(node* root, string s) {
  //printf("ffinding %s\n", s.c_str());
  for(int i = 0; i < s.size(); i++) {
    if(root->child[s[i] - 'A'] == NULL) {
      return {-1, -1};
    }
    root = root->child[s[i] - 'A'];
  }
  return {root->l, root->r};
}

vector<string> s;
int id;

void dfs(node* now) {
  now->l = id++;
  for(int i = 0; i < 26; i++) {
    if(now->child[i] != NULL) {
      dfs(now->child[i]);
    }
  }
  now->r = id - 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  node* root_front = new node();
  node* root_back = new node();

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string buf;
    cin >> buf;
    s.push_back(buf);
    add(root_front, buf);
    reverse(buf.begin(), buf.end());
    add(root_back, buf);
  }
  id = 0;
  dfs(root_front);
  id = 0;
  dfs(root_back);
  // cout << num_node_front << " ancok " << num_node_back << endl;

  vector<pair<int, int>> all;
  for(int i = 0; i < n; i++) {
    string buf = s[i];
    int a = find(root_front, buf);
    reverse(buf.begin(), buf.end());
    int b = find(root_back, buf);
    all.emplace_back(a, b);
  }
  sort(all.begin(), all.end());
  //for(auto it : all) printf("%d %d\n", it.first, it.second);
  segtree seg(all);
  while(m--) {
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    pair<int, int> f = find_pair(root_front, a);
    pair<int, int> g = find_pair(root_back, b);
    //puts("done find");
    if(f.first == -1 || g.first == -1) {
      puts("0");
      continue;
    }
    printf("%d\n", seg.find(f.first, f.second, g.first, g.second));
  }

  return 0;
}
