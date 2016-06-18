#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int node = 2e5 + 5;

int a[N];

int b[node], d[node];
char s[node];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, p, k;
    scanf("%d %d %d", &n, &a[0], &k);
    for(int i = 1; i <= k; i++) {
      scanf("%d", a + i);
    }
    vector<char> ans;
    for(int i = 0; i < k; i++) {
      fill(d, d + node, 1e9);
      int from = a[i];
      int to = a[i + 1];

      d[from] = 0;
      queue<int> q;
      q.push(from);
      while(!q.empty()) {
        int id = q.front();
        q.pop();
        if(id == to) break;
        if(id <= n) {
          if(d[2 * id] > d[id] + 1) {
            d[2 * id] = d[id] + 1;
            b[2 * id] = id;
            s[2 * id] = 'L';
            q.push(2 * id);
          }
          if(d[2 * id - 1] > d[id] + 1) {
            d[2 * id - 1] = d[id] + 1;
            b[2 * id - 1] = id;
            s[2 * id - 1] = 'R';
            q.push(2 * id - 1);
          }
        } else {
          id -= n;
          if(d[2 * id] > d[id+n] + 1) {
            d[2 * id] = d[id+n] + 1;
            b[2 * id] = id+n;
            s[2 * id] = 'R';
            q.push(2 * id);
          }
          if(d[2 * id - 1] > d[id+n] + 1) {
            d[2 * id - 1] = d[id+n] + 1;
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
