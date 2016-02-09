#include <bits/stdc++.h>
#include <sys/resource.h>

using namespace std;

const int inf = 1e9;
const int N = 1e6 + 5;

void init_stack() {
  const rlim_t STACK_SIZE = 150 * 1024 * 1024;
  struct rlimit rl;
  rl.rlim_cur = STACK_SIZE;
  setrlimit(RLIMIT_STACK, &rl);
}

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

vector<vector<int>> vis;
vector<vector<char>> s;
int n, m, ans;
queue<pair<int, int>> q;
char buf[N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int a, int b) {
  ans = max(ans, vis[a][b]);
  for(int i = 0; i < 4; i++) {
    int ta = a + da[i];
    int tb = b + db[i];
    if(valid(ta, tb)) {
      if(s[ta][tb] == s[a][b]) {
        if(vis[a][b] < vis[ta][tb]) {
          vis[ta][tb] = vis[a][b];
          dfs(ta, tb);
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

int main() {
  init_stack();
  
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
    ans = 0;
    while(!q.empty()) {
      int a, b;
      tie(a, b) = q.front();
      q.pop();
      dfs(a, b);
    }
    cout << ans << endl;
  }
  
  return 0;
}
