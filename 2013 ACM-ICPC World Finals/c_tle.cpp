#include <bits/stdc++.h>

using namespace std;

const int N = 25005;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 25e6 + 5;
#define ll long long

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

const int INF = 1e9;       
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
    queue<ll> q;
    q.push(s);
    fill(prio, prio + nodes, INF);
    prio[s]=0;
    curflow[s]= INF;
    while(!q.empty()){
      ll cur = q.front();
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
    if(prio[t] == INF)break;
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

vector<pair<int, int>> adj[N], edge[N];
int d[N], c[N];
map<int, int> mp[N];
int num_nodes;

int get_id(int now, int timestamp) {
  if (!mp[now].count(timestamp)) {
    mp[now][timestamp] = num_nodes++;
  }
  return mp[now][timestamp];
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  while (m--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  while (k--) {
    int v;
    scanf("%d", &v);
    c[v]++;
  }

  fill(d, d + N, INF);
  priority_queue<pair<int, int>> pq;
  d[1] = 0;
  pq.emplace(-d[1], 1);
  while (!pq.empty()) {
    int now, cost;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if (d[now] != cost) continue;
    for (auto it : adj[now]) {
      int near = it.first;
      int ncos = cost + it.second;
      if (d[near] > ncos) {
        d[near] = ncos;
        pq.emplace(-d[near], near);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) {
      if (d[i] - it.second == d[it.first]) {
        edge[i].push_back(it);
      }
    }
  }

  // pq: time - node
  for (int i = 1; i <= n; i++) if (c[i]) {
    pq.emplace(0, i);
    get_id(i, 0);
  }
  while (!pq.empty()) {
    int time, now;
    tie(time, now) = pq.top();
    time = -time;
    int id_from = get_id(now, time);
    pq.pop();
    for (auto it : edge[now]) {
      int near = it.first;
      int ntime = time + it.second;
      if (!mp[near].count(ntime)) {
        pq.emplace(-ntime, near);
      }
      int id_to = get_id(near, ntime);
      addEdge(id_from, id_to, 1, 0);
      // printf("%d -> %d: %d\n", id_from, id_to, 1);
      // printf("%d time %d -> %d time %d\n\n", now, time, near, ntime);
    }
  }
  int source = num_nodes++;
  int sink = num_nodes++;
  for (int i = 1; i <= n; i++) if (c[i]) {
    // printf("%d -> %d: %d\n", source, get_id(i, 0), c[i]);
    addEdge(source, get_id(i, 0), c[i], 0);
  }
  for (auto it : mp[1]) {
    // printf("%d -> %d: %d\n", it.second, sink, INF);
    addEdge(it.second, sink, INF, 0);
  }
  cout << minCostFlow(source, sink, INF).first << endl;

  return 0;
}
