#include <bits/stdc++.h>
using namespace std;

map<int,bool> MAP;
const int N = 50, C = 1e4;
vector<int> ar[N + 5];
int n;
vector<int> uniq;

int jum[C + 5];
int connect[C + 5];

int main(){
  int tc = 0;
  while(scanf("%d", &n) != EOF){
    ++tc;
    memset(jum, 0, sizeof jum);
    memset(connect, 0, sizeof connect);
    
    for(int i = 0;i < n; ++i) ar[i].clear();
    uniq.clear();
    for(int i = 0;i < n; ++i){
      int h;
      scanf("%d", &h);
      for(int j = 0;j < h; ++j){
        int x;
        scanf("%d", &x);
        if(!MAP.count(x)){
          MAP[x] = true;
          uniq.push_back(x);
        }
        ar[i].push_back(x);
        jum[x]++;
      }
    }
    sort(uniq.begin(), uniq.end());
    
    int connected_component = n;
    int split = 0;
    for(int i = 0;i < n; ++i){
      int color = ar[0];
      for(int j = 1; j < (int) ar[i].size(); ++j){
        if(ar[i][j] != ar[i][j - 1]){
          
        }
      }
    }
    int ans = split + connected_component - 1;
    printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}
