#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<pair<int, int>, int> p[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p[i] = make_pair(make_pair(min(b, n - a + 1), max(b, n - a + 1)), i + 1);
  }
  sort(p, p + m);
  /*
  puts("JANCOK");
  for(int i = 0; i < m; i++) {
    printf("%d %d\n", p[i].first.first, p[i].first.second);
  }
  */
  int t = 0;
  multiset<pair<int, int>> sed;
  vector<int> ans;
  for(int c = 1, i = 0; c <= n; c++) {
    while(i < m && p[i].first.first <= c) {
      sed.insert(make_pair(p[i].first.second, p[i].second));
      i++;
    }
    vector<pair<int,int>> toErase;
    for(auto it : sed) {
      if(it.first < c) {
        toErase.push_back(it);
      } else {
        break;
      }
    }
    for(auto it : toErase) {
      sed.erase(sed.find(it));
    }
/*
    printf("ITERASI %d\n", c);
    for(auto it : sed) {
      printf("%d %d\n", it.first, it.second);
    }
*/
    if(sed.size()) {
      ans.push_back(sed.begin()->second);
      sed.erase(sed.begin());
    }

  }
  cout << ans.size() << endl;
  for(auto it : ans) {
    printf("%d ", it);
  }
  return 0;
}
