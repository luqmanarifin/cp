#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 1e4 + 5;
const int inf = 1e9;

#define ll long long

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s,int t,int cap,int cost){
  Edge a ={t,0, cap, cost, (int) graph[t].size()};
  Edge b ={s,0,0,-cost, (int) graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(int s,int dist[]){
  fill(dist, dist + nodes,1000000000);
  dist[s]=0;
  int qt =0;
  q[qt++]= s;
  for(int qh =0;(qh - qt)% nodes !=0; qh++){
    int u = q[qh % nodes];
    inqueue[u]=false;
    for(int i =0; i <(int) graph[u].size(); i++){
      Edge &e = graph[u][i];
      if(e.cap <= e.f)continue;
      int v = e.to;
      int ndist = dist[u]+ e.cost;
      if(dist[v]> ndist){
        dist[v]= ndist;
        if(!inqueue[v]){
          inqueue[v]=true;
          q[qt++% nodes]= v;
        }
      }
    }
  }
}


pair<int, int> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  // bellmanFord(s, pot);
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
    queue<int> q;
    q.push(s);
    inqueue[s] = 1;
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      int u = q.front();
      int d = prio[u];
      q.pop();
      inqueue[u] = 0;
      if(d != prio[u])continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        int nprio = prio[u]+ e.cost;
        if(prio[v]> nprio){
          prio[v]= nprio;
          if (!inqueue[v]) {
            q.push(v);
            inqueue[v] = 1;
          }
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==1000000000)break;
    for(int i =0; i < nodes; i++) pot[i]+= prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for(int v = t; v != s; v = prevnode[v]){
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}


/* usage example:
* addEdge (source, target, capacity, cost)
* minCostFlow(source, target, INF) -><flow, flowCost>
*/

const int N = 5005;

pair<int, int> s[N];
tuple<int, int, int> p[N];  // capacity, cost, id
int tmp[N], r[N], ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    s[i] = {v, i};
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", tmp + i);
  }
  for (int i = 1; i <= m; i++) {
    int v;
    scanf("%d", &v);
    p[i] = make_tuple(tmp[i], v, i);
  }
  sort(s + 1, s + 1 + n);
  sort(p + 1, p + 1 + m);
  int nodes = n + m + 2;
  for (int i = 1; i <= n; i++) {
    int at = lower_bound(p + 1, p + 1 + m, make_tuple(s[i].first, -1, -1)) - p;
    //printf("%d %d\n", i, at);
    if (at <= m) {
      addEdge(i, n + at, 1, 0);
    }
    addEdge(0, i, 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    int cost;
    tie(ignore, cost, ignore) = p[i];
    addEdge(n + i, nodes - 1, 1, cost);
    if (i + 1 <= m) {
      addEdge(n + i, n + i + 1, inf, 0);
    }
  }
  auto ret = minCostFlow(0, nodes - 1, inf);
  if (ret.first != n) {
    puts("impossible");
    return 0;
  }
  //cout << ret.second << endl;
  vector<int> num;
  for (int i = 1; i <= m; i++) {
    for (auto e : graph[n + i]) {
      if (e.to == nodes - 1 && e.f == 1) {
        int id;
        tie(ignore, ignore, id) = p[i];
        num.push_back(id);
      }
    }
  }
  assert(num.size() == n);
  for (int i = 1; i <= n; i++) {
    ans[s[i].second] = num[i - 1];
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
  
  return 0;
}
