#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1e5 + 5;

struct photo {
  int type;     // 0, horizontal, 1 vertical
  int id1;
  int id2;
  vector<int> tag;
  photo(int type, int id1, int id2, vector<int> tag) : type(type), id1(id1), id2(id2), tag(tag) {}
};

vector<int> join(vector<int> tag1, vector<int> tag2) {
  set<int> s;
  for (auto it : tag1) s.insert(it);
  for (auto it : tag2) s.insert(it);
  vector<int> v;
  for (auto it : s) v.push_back(it);
  return v; 
}

// assume id of tag is sorted
int score(vector<int> tag1, vector<int> tag2) {
  int i = 0, j = 0;
  int same = 0;
  while (i < tag1.size() && j < tag2.size()) {
    if (tag1[i] < tag2[j]) {
      i++;
    } else if (tag1[i] > tag2[j]) {
      j++;
    } else {
      same++;
      i++;
      j++;
    }
  }
  return min(same, (int)min(tag1.size() - same, tag2.size() - same));
}

void randomize(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    int id = rand() % a.size();
    swap(a[i], a[id]);
  }
}

void randomize(vector<photo>& a) {
  for (int i = 0; i < a.size(); i++) {
    int id = rand() % a.size();
    swap(a[i], a[id]);
  }
}

void randomize(vector<pair<int, int> >& a) {
  for (int i = 0; i < a.size(); i++) {
    int id = rand() % a.size();
    swap(a[i], a[id]);
  }
}

vector<photo> sort_first_last(vector<photo> a) {
  vector<photo> block[101];
  for (int i = 0; i < a.size(); i++) {
    assert(a[i].type == 1);
    block[a[i].tag.size()].push_back(a[i]);
  }
  for (int i = 1; i <= 100; i++) {
    randomize(block[i]);
  }
  vector<photo> linear;
  for (int i = 1; i <= 100; i++) {
    for (auto it : block[i]) {
      linear.push_back(it);
    }
  }
  vector<photo> ret;
  for (int i = 0; i < linear.size(); i++) {
    int j = (int)linear.size() - 1 - i;
    if (i < j) {
      ret.push_back(photo(0, a[i].id1, a[j].id1, join(a[i].tag, a[j].tag)));
    } else{
      break;
    }
  }
  return ret;
}

vector<int> edge[10005];
vector<int> par, deg;

int find_corner(int u, int bef) {
  for (auto it : edge[u]) {
    if (it != bef) {
      return find_corner(it, u);
    }
  }
  return u;
}

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

struct slideshow {
  slideshow(vector<photo> photos) {
    database = photos;
  }
  // array of block, block is array of ID
  vector<vector<int> > divide_to_blocks(int size_per_block) {
    vector<int> block[201];
    for (int i = 0; i < database.size(); i++) {
      block[database[i].tag.size()].push_back(i);
    }
    for (int i = 0; i < 201; i++) {
      randomize(block[i]);
    }
    vector<vector<int>> ret;
    int last = 0;
    for (int i = 0; i < 201; i++) {
      for (auto it : block[i]) {
        if (ret.size() == last) {
          vector<int> a;
          ret.push_back(a);
          ret[last].push_back(it);
        } else {
          ret[last].push_back(it);
          if (ret[last].size() == size_per_block) {
            last++;
          }
        }
      }
    }
    return ret;
  }

  // sort the things
  vector<int> kruskal(vector<int> id){
    vector<pair<int, int> > edges[101];
    for (int i = 0; i < id.size(); i++) {
      for (int j = i + 1; j < id.size(); j++) {
        int sc = score(database[id[i]].tag, database[id[j]].tag);
        edges[sc].emplace_back(i, j);      }
    }
    for (int i = 0; i < 101; i++) {
      randomize(edges[i]);
    }
    par.clear();
    deg.clear();
    for (int i = 0; i < id.size(); i++) {
      par.push_back(i);
      deg.push_back(0);
      edge[i].clear();
    }

    // puts("done");



    for (int block = 100; block >= 0; block--) {
      for (auto it : edges[block]) {
        int u = it.first;
        int v = it.second;
        if (find(u) != find(v) && deg[u] <= 1 && deg[v] <= 1) {
          merge(u, v);
          deg[u]++;
          deg[v]++;
          edge[u].push_back(v);
          edge[v].push_back(u);
        }
      }
    }
    // puts("linear done");
    vector<int> ret;
    int now = find_corner(0, -1), bef = -1;
    ret.push_back(id[now]);
    while (1) {
      int near = -1;
      for (auto it : edge[now]) {
        if (it == bef) continue;
        near = it;
        ret.push_back(id[it]);
        bef = now;
        now = it;
        break;
      }
      if (near == -1) break;
    }
    return ret;
  }

  vector<int> prim(vector<int> id){
    vector<pair<int, int> > edges[101];
    for (int i = 0; i < id.size(); i++) {
      for (int j = i + 1; j < id.size(); j++) {
        int sc = score(database[id[i]].tag, database[id[j]].tag);
        edges[sc].emplace_back(i, j);      }
    }
    for (int i = 0; i < 101; i++) {
      randomize(edges[i]);
    }
    par.clear();
    deg.clear();
    for (int i = 0; i < id.size(); i++) {
      par.push_back(i);
      deg.push_back(0);
      edge[i].clear();
    }

    // puts("done");



    for (int block = 100; block >= 0; block--) {
      for (auto it : edges[block]) {
        int u = it.first;
        int v = it.second;
        if (find(u) != find(v) && deg[u] <= 1 && deg[v] <= 1) {
          merge(u, v);
          deg[u]++;
          deg[v]++;
          edge[u].push_back(v);
          edge[v].push_back(u);
        }
      }
    }
    // puts("linear done");
    vector<int> ret;
    int now = find_corner(0, -1), bef = -1;
    ret.push_back(id[now]);
    while (1) {
      int near = -1;
      for (auto it : edge[now]) {
        if (it == bef) continue;
        near = it;
        ret.push_back(id[it]);
        bef = now;
        now = it;
        break;
      }
      if (near == -1) break;
    }
    return ret;
  }


  // static (only pass the ID everywhere)
  vector<photo> database;
};

map<string, int> mp;
int cntr;

int get(string s) {
  if (!mp.count(s)) {
    mp[s] = cntr++;
  }
  return mp[s];
}

char buf[20];

vector<photo> read() {
  mp.clear();
  cntr = 0;

  vector<photo> ret;

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char c;
    scanf(" %c", &c);
    vector<int> tag;
    int k;
    scanf("%d", &k);
    while (k--) {
      scanf("%s", buf);
      string str = string(buf);
      tag.push_back(get(str));
    }
    sort(tag.begin(), tag.end());
    if (c == 'H') {
      ret.push_back(photo(0, i, -1, tag));
    } else {
      ret.push_back(photo(1, i, -1, tag));
    }
  } 
  return ret;
}


int main(void)
{
  srand(time(0));
  //ios_base::sync_with_stdio(false);
  //open;
  auto photos = read();
  vector<photo> ver, hor;
  for (auto it : photos) {
    if (it.type == 1) {
      ver.push_back(it);
    } else {
      hor.push_back(it);
    }
  }
  ver = sort_first_last(ver);
  photos = ver;
  for (auto it : hor) photos.push_back(it);

  // for (auto it : photos) printf("%d %d %d\n", it.type, it.id1, it.id2);

  // puts("vertikal horizontal done");

  slideshow solver(photos);
  auto blocks = solver.divide_to_blocks(10000);
  // set<int> all;
  // for (auto block : blocks) {
  //   for (auto id : block) {
  //     all.insert(id);
  //   }
  // }
  // assert(all.size() == photos.size());

  // puts("divide to blocks done");
  vector<pair<int, int>> ans;
  for (auto block : blocks) {
    auto ids = solver.kruskal(block);
    for (auto i : ids) {
      // printf("%d ", i);
      ans.emplace_back(solver.database[i].id1, solver.database[i].id2);
    }
    // puts("solver");
  }
  // puts("solver done");
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    int u = it.first;
    int v = it.second;
    if (v == -1) {
      printf("%d\n", u);
    } else {
      printf("%d %d\n", u, v);
    }
  }
  
  //close;
  return 0;
}