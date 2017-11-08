#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 1e4 + 5;

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
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
    queue<int> q;
    q.push(s);
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      int u = q.front();
      int d = prio[u];
      inqueue[u] = false;
      q.pop();
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        int nprio = prio[u]+ e.cost;
        if(prio[v]> nprio){
          prio[v]= nprio;
          if (!inqueue[v]) {
            inqueue[v] = true;
            q.push(v);
          }
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==1000000000)break;
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

int s[N], p[N], r[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", s + i);
  for (int i = 1; i <= m; i++) scanf("%d", p + i);
  for (int i = 1; i <= m; i++) scanf("%d", r + i);
  int nodes = n + m + 2;
  for (int i = 1; i <= n; i++) {
    addEdge(0, i, 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    addEdge(n + i, nodes - 1, 1, r[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i] <= p[j]) {
        addEdge(i, n + j, 1, 0);
      }
    }
  }
  auto it = minCostFlow(0, nodes - 1, 1000000000);
  if (it.first != n) {
    puts("impossible");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (auto e : graph[i]) {
      if (n < e.to && e.to < nodes - 1 && e.f > 0) {
        printf("%d%c", e.to - n, " \n"[i == n]);
      }
    }
  }
  return 0;
}
