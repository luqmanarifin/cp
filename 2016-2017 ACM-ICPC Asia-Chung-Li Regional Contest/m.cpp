#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 205;

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

pair<int, int> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  // bellmanFord(s, pot);
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(s);
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      ll cur = q.top();
      int d = cur >>32;
      int u = cur;
      q.pop();
      if(d != prio[u])continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        int nprio = prio[u]+ e.cost + pot[u]- pot[v];
        if(prio[v]> nprio){
          prio[v]= nprio;
          q.push(((ll) nprio <<32)+ v);
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

const int N = 105;
const int inf = 1e9;

vector<pair<int, int>> edge[N];
int deg[N], dist[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(deg, 0, sizeof(deg));
    
    for (int i = 0; i < maxnodes; i++) graph[i].clear();
    for (int i = 0; i < N; i++) edge[i].clear();
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    deg[s] = deg[t] = 1;
    int sum = 0;
    
    vector<int> num;
    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
      sum += c;
    }
    for (int i = 1; i <= n; i++) {
      if (edge[i].size() % 2 != deg[i]) {
        num.push_back(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = inf;
      }
      dist[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (auto it : edge[i]) {
        dist[i][it.first] = min(dist[i][it.first], it.second);
      }
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int nodes = 2 * n + 2;
    for (int i = 0; i < num.size(); i++) {
      addEdge(0, num[i], 1, 0);
      addEdge(n + num[i], nodes - 1, 1, 0);
      for (int j = i + 1; j < num.size(); j++) {
        addEdge(num[i], n + num[j], 1, dist[num[i]][num[j]]);
        addEdge(num[j], n + num[i], 1, dist[num[i]][num[j]]);
      }
    }
    sum += minCostFlow(0, nodes - 1, inf).second / 2;
    printf("%d\n", sum);
  }

  return 0;
}
