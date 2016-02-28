#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>
#include <cassert>

#define EPS 1e-11
#define PI acos(-1)
#define LL long long
#define INF 1000000009
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define SZ(a) ((int)a.size())
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)
#define pii pair<LL,LL>

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

int ar[105][105];

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
  
  void GetVal(int nn) {
  	for (int i=0;i<G.size();i++)
  	{
  		for (int j=0;j<G[i].size();j++)
  		{
  			int a = G[i][j].from;
  			int b = G[i][j].to;
  			int f = G[i][j].flow;
  			Edge e = G[i][j];
  		//	printf("%d %d %d %d %d ar[%d][%d]=%d\n",e.from, e.to, e.cap, e.flow, e.index, a,b,f);
	  		if (f>0 && a>=1 && a<=nn && b>=nn+1 && b<=2*nn) ar[a][b-nn] = f;
  		}
  	}
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!dad[e.to] && e.cap - e.flow > 0) {
      dad[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int n,m;
int a[105],b[105];

int main()
{
	scanf("%d %d",&n,&m);
	
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	
	Dinic din(2*n+2);
	
	int source = 0;
	int sink = 2*n+1;
	
	int tot = 0;
	int tot2 = 0 ;
	
	for (int i=1;i<=n;i++) tot += a[i];
	for (int i=1;i<=n;i++) tot2 += b[i];
	if (tot != tot2)
	{
		printf("NO\n");
		return 0;
	}
	
	for (int i=1;i<=n;i++) din.AddEdge(source, i, a[i]);
	for (int i=1;i<=n;i++) din.AddEdge(n+i, sink, b[i]);
	
	while(m--)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		
		din.AddEdge(u,v+n,INF);
		din.AddEdge(v,u+n,INF);
	}
	for (int i=1;i<=n;i++) din.AddEdge(i,n+i,a[i]);
	
	int res = din.GetMaxFlow(source, sink);
	
	if (tot!=res) printf("NO\n");
	else
	{
		din.GetVal(n);
		printf("YES\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) printf("%d ",ar[i][j]);
			printf("\n");
		}
	}
	

	return 0;
}