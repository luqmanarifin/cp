#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

long long a[N];

map<long long, long long> b;
map<long long, char> s;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, p, k;
    scanf("%d %lld %d", &n, &a[0], &k);
    for(int i = 1; i <= k; i++) {
      scanf("%lld", a + i);
    }
    vector<char> ans;
    for(int i = 0; i < k; i++) {
      b.clear();
      s.clear();
      long long from = a[i];
      long long to = a[i + 1];

      set<long long> d;
      d.insert(from);
      queue<long long> q;
      q.push(from);
      while(!q.empty()) {
        long long id = q.front();
        q.pop();
        if(id == to) break;
        if(id <= n) {
          if(!d.count(2 * id)) {
            d.insert(2 * id);
            b[2 * id] = id;
            s[2 * id] = 'L';
            q.push(2 * id);
          }
          if(!d.count(2 * id - 1)) {
            d.insert(2 * id - 1);
            b[2 * id - 1] = id;
            s[2 * id - 1] = 'R';
            q.push(2 * id - 1);
          }
        } else {
          id -= n;
          if(!d.count(2 * id)) {
            d.insert(2 * id);
            b[2 * id] = id+n;
            s[2 * id] = 'R';
            q.push(2 * id);
          }
          if(!d.count(2 * id - 1)) {
            d.insert(2 * id - 1);
            b[2 * id - 1] = id+n;
            s[2 * id - 1] = 'L';
            q.push(2 * id - 1);
          }
        }
      }
      vector<char> st;
      while(to != from) {
        st.push_back(s[to]);
        to = b[to];
      }
      reverse(st.begin(), st.end());
      for(auto it : st) ans.push_back(it);
    }
    printf("%d:", ans.size());
    for(auto it : ans) printf("%c", it); printf("\n");
    cerr << tt << " found" << endl;
  }

  return 0;
}
