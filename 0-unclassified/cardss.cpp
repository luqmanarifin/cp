#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int a[N][N][N];
char s[N];
vector<char> ans;

void dfs(int r, int g, int b) {
  if(a[r][g][b]) return;
  a[r][g][b] = 1;
  if(r + g + b == 1) {
    if(r) {
      ans.push_back('R');
    }
    if(g) {
      ans.push_back('G');
    }
    if(b) {
      ans.push_back('B');
    }
    return;
  }
  if(r && g) dfs(r - 1, g - 1, b + 1);
  if(g && b) dfs(r + 1, g - 1, b - 1);
  if(r && b) dfs(r - 1, g + 1, b - 1);
  if(r >= 2) dfs(r - 1, g, b);
  if(g >= 2) dfs(r, g - 1, b);
  if(b >= 2) dfs(r, g, b - 1);
}

int main() {
  int n;
  scanf("%d %s", &n, s);
  int r = 0, g = 0, b = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'R') {
      r++;
    } else if(s[i] == 'G') {
      g++;
    } else {
      b++;
    }
  }
  dfs(r, g, b);
  sort(ans.begin(), ans.end());
  ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
  for(auto it : ans) printf("%c", it);
  return 0;
}