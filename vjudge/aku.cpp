#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

map<string, int> mapping;
int num;
vector<int> edge[N];
bool f[N][N];
string user[N];
int cur[N];
int ans[N];

int get(string s) {
  if(mapping[s]) return mapping[s];
  user[++num] = s;
  return mapping[s] = num;
}

int main() {
  ios_base::sync_with_stdio(false);
  int m;
  cin >> m;
  while(m--) {
    string a, b;
    cin >> a >> b;
    int ia = get(a);
    int ib = get(b);
    edge[ia].push_back(ib);
    edge[ib].push_back(ia);
    f[ia][ib] = f[ib][ia] = 1;
  }
  for(int i = 1; i <= num; i++) {
    for(int j = 1; j <= num; j++) {
      cur[j] = 0;
    }
    int maxi = 0;
    for(auto it : edge[i]) {
      for(auto acq : edge[it]) {
        if(!f[i][acq] && i != acq) {
          cur[acq]++;
          maxi = max(maxi, cur[acq]);
        }
      }
    }
    for(int j = 1; j <= num; j++) {
      if(i == j || f[i][j]) {
        continue;
      }
      if(cur[j] == maxi) {
        ans[i]++;
      }
    }
  }
  printf("%d\n", num);
  for(int i = 1; i <= num; i++) {
    printf("%s %d\n", user[i].c_str(), ans[i]);
  }
  
  return 0;
}