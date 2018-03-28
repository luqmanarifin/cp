#include <bits/stdc++.h>

using namespace std;

const int N = 25005;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 25005;
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
  memset(curflow, 0, sizeof(curflow));
  memset(prevedge, 0, sizeof(curflow));
  memset(prevnode, 0, sizeof(curflow));
  memset(q, 0, sizeof(curflow));
  memset(pot, 0, sizeof(curflow));
  while(flow < maxf){
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(s);
    fill(prio, prio + nodes, INF);
    prio[s]=0;
    curflow[s]= INF;
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
  // at - node
  vector<pair<int, int>> pos;

  // pq: time - node
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < c[i]; j++) {
      pos.emplace_back(d[i], i);
    }
  }
  sort(pos.begin(), pos.end());
  int ans = 0;
  for (int it = 0; it < pos.size(); it++) {
    int j = it;
    while (j + 1 < pos.size() && pos[j + 1].first == pos[j].first) j++;
    for (int i = 0; i <= n; i++) graph[i].clear();
    for (int i = 1; i <= n; i++) {
      for (auto near : edge[i]) {
        addEdge(i, near.first, 1, 0);
      }
    }
    for (int i = it; i <= j; i++) {
      addEdge(0, pos[i].second, 1, 0);
    }
    ans += minCostFlow(0, 1, INF).first;
    it = j;
  }

  cout << ans << endl;

  return 0;
}