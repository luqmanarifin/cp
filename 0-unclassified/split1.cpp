#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e6 + 5;

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

vector<vector<int>> vis;
vector<vector<char>> s;
int n, m;
queue<pair<int, int>> q;
char buf[N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    vis.assign(n, vector<int>(m));
    s.assign(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
      scanf("%s", buf);
      for(int j = 0; j < m; j++) {
        s[i][j] = buf[j];
        vis[i][j] = inf;
      }
    }
    while(!q.empty()) q.pop();
    q.emplace(0, 0);
    vis[0][0] = 0;
    int ans = 0;
    while(!q.empty()) {
      int a, b;
      tie(a, b) = q.front();
      q.pop();
      stack<pair<int, int>> st;
      st.emplace(a, b);
      while(!st.empty()) {
        tie(a, b) = st.top();
        st.pop();
        ans = max(ans, vis[a][b]);
        for(int i = 0; i < 4; i++) {
          int ta = a + da[i];
          int tb = b + db[i];
          if(valid(ta, tb)) {
            if(s[ta][tb] == s[a][b]) {
              if(vis[a][b] < vis[ta][tb]) {
                vis[ta][tb] = vis[a][b];
                st.emplace(ta, tb);
              }
            } else {
              if(vis[a][b] + 1 < vis[ta][tb]) {
                vis[ta][tb] = vis[a][b] + 1;
                q.emplace(ta, tb);
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
