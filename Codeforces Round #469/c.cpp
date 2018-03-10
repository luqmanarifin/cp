/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

// input
int u[N], c1[N], c2[N];

vector<int> edge[N];            // node
vector<int> el[N];              // supernode
int node[N];                    // node
int super_edges[N];             // supernode

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : edge[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el[numCC].push_back(u);
      node[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  for (int i = 1; i <= n; i++) scanf("%d", u + i);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", c1 + i, c2 + i);
    if ((u[c1[i]] + 1) % h == u[c2[i]]) {
      edge[c1[i]].push_back(c2[i]);
    }
    if ((u[c2[i]] + 1) % h == u[c1[i]]) {
      edge[c2[i]].push_back(c1[i]);
    }
  }
  // In MAIN();
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  for (int i = 1; i <= n; i++) {
    for (auto it : edge[i]) {
      if (node[i] != node[it]) {
        super_edges[node[i]]++;
      }
    }
  }
  int ans = 1e9, at = -1;
  for (int i = 0; i < numCC; i++) {
    if (super_edges[i] == 0 && el[i].size() < ans) {
      ans = el[i].size();
      at = i;
    }
  }  
  printf("%d\n", ans);
  for (auto it : el[at]) printf("%d ", it);
    
  return 0;
}
