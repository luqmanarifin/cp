#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 6010;

typedef long long ll;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

           
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s,int t,int cap,int cost){
  Edge a ={t,0, cap, cost, graph[t].size()};
  Edge b ={s,0,0,-cost, graph[s].size()};
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

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  nodes = n + 2 + 2;
  int s = nodes - 2, t = nodes - 1;
  for (int i = 0; i < n; i++)
    addEdge(s, i, 1, 0);
  addEdge(n, t, a, 0);
  addEdge(n+1, t, b, 0);
  for (int i = 0; i < n; i++) {
    int ty, w;
    scanf("%d %d", &ty, &w);
    if (ty & 1)
      addEdge(i, n, 1, w);
    if (ty & 2)
      addEdge(i, n+1, 1, w);
  }
  pair<int, int> res = minCostFlow(s, t, n);
  printf("%d %d\n", res.first, res.second);
  int aa = 1, bb = a + 1;
  for (int i = 0; i < n; i++) {
    int pil = -1;
    for (Edge & e : graph[i]) {
      if (e.f <= 0) continue;
      if (e.to != n && e.to != n+1) continue;
      pil = e.to;
    }
    if (pil == -1) continue;
    if (pil == n)
      printf("%d %d\n", i+1, aa++);
    else
      printf("%d %d\n", i+1, bb++);
  }
  return 0;
}
