/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it:
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
Surely, just as we were that day... like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy...
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light;
Even if you never change... even if you happen to change... you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people;
At that time, I hope we can bring along our irreplaceable families and meet here again...

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light...
We run through the passing seasons, seeing each of our many tomorrows;
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 1e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N], el[N];
int par[N];

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      par[u] = numCC;
      el[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int to[N], ke[M];
vector<int> edge[N];

// 1 ada siklik
bool siklik(int id, int haram) {
  memset(to, 0, sizeof(to));
  for (auto i : el[id]) {
    for (auto it : edge[i]) {
      if (it == haram) continue;
      to[ke[it]]++;
    }
  }
  int done = 0;
  queue<int> q;
  for (auto i : el[id]) if (to[i] == 0) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    done++;
    for (auto it : edge[now]) {
      if (it == haram) continue;
      to[ke[it]]--;
      if (to[ke[it]] == 0) {
        q.push(ke[it]);
      }
    }
  }
  return done < el[id].size();
}

bool can(int id) {
  int pt = 0;
  for (auto it : el[id]) {
    for (auto jt : adj[it]) {
      if (par[jt] == id) {
        ke[pt] = jt;
        edge[it].push_back(pt);
        pt++;
        to[jt]++;
      }
    }
  }
  for (auto i : el[id]) {
    for (auto it : edge[i]) {
      if (to[ke[it]] == 1) {
        if (!siklik(id, it)) return 1;
      }
    }
  }
  return 0;
}  

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }
  num.assign(N, -1);
  low.assign(N, 0);
  vis.assign(N, 0);
  cntr = numCC = 0;
  for(int i = 1; i <= n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  
  int cyc = 0;
  for (int i = 0; i < numCC; i++) {
    if (el[i].size() > 1) {
      if (cyc) {
        puts("NO");
        return 0;
      }
      cyc = 1;
      if (!can(i)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
