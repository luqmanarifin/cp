#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int, double> pid;
#define fi first
#define se second

priority_queue<pii, vector<pii>, greater<pii> > pq;
const int N = 3e5;
pid ar[N + 5];
int n, m;
bool visit[N + 5];
int tim[N + 5];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n; ++i) scanf("%d%lf", &ar[i].fi, &ar[i].se);
  for(int i = 0;i < min(m, n); ++i){
    pq.push({ar[i].fi, i});
  }
  int poi = min(n, m);
  int poiarray = 0;
  while(!pq.empty()){
    pii tmp = pq.top(); pq.pop();
    if(poi < n) pq.push({tmp.fi + ar[poi].fi, poi}), poi++;
    visit[tmp.se] = 1;
    while(poiarray < n && visit[poiarray]){
      tim[poiarray] = tmp.fi;
      poiarray++;
    }
  }
  double tot = 0;
  double prob = 1;
  for(int i = 0;i < n; ++i){
    tot += prob * (1 - ar[i].se) * tim[i];
    prob *= ar[i].se;
  }
  tot += prob * tim[n - 1];
  
  printf("%.10lf\n", tot);
  return 0;
}