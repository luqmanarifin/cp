#include <bits/stdc++.h>

using namespace std;
const string filename = "A";

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
typedef long long ll;
const int maxnodes = 5050;
const ll inf = 1e17;


int nodes = maxnodes;
ll prio[maxnodes];
int curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes];
ll pot[maxnodes];
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

void bellmanFord(int s,ll dist[]){
  fill(dist, dist + nodes,inf);
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
      ll ndist = dist[u]+ e.cost;
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


pair<int, ll> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  bellmanFord(s, pot);
  int flow =0;
  ll flowCost =0;
  while(flow < maxf){
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int>>> q;
    q.push(make_pair(0LL, s));
    fill(prio, prio + nodes,inf);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      pair<long long, int> cur = q.top();
      ll d = cur.first;
      int u = cur.second;
      q.pop();
      if(d != prio[u])continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
        ll nprio = prio[u]+ e.cost + pot[u]- pot[v];
        if(prio[v]> nprio){
          prio[v]= nprio;
          q.push(make_pair(nprio, v));
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==inf)break;
    for(int i =0; i < nodes; i++) pot[i]+= prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for(int v = t; v != s; v = prevnode[v]){
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += 1LL * df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}


/* usage example:
* addEdge (source, target, capacity, cost)
* minCostFlow(source, target, INF) -><flow, flowCost>
*/

const int N = 1024;

int e[N], s[N];

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif

  int n, k, ms, me;
  scanf("%d %d %d %d", &n, &k, &ms, &me);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", e+i);
  for (int i = 0; i < n; ++i) {
    addEdge(i, i+n, 1, s[i]);
    addEdge(i, i+2*n, 1, e[i]);
  }
DONE:;
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}