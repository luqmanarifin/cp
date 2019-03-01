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


struct photo {
  int type;     // 0, horizontal, 1 vertical
  int id1;
  int id2;
  vector<int> tag;
  photo(int type, int id1, int id2, vector<int> tag) : type(type), id1(id1), id2(id2), tag(tag) {}
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
  //ios_base::sync_with_stdio(false);
  //open;
  auto photos = read();
  cout << cntr << endl;
  
  
  //close;
  return 0;
}