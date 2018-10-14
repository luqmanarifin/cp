/*

Hello, it's me
I was wondering if after all these weeks you'd like to meet
To go over everything
They say that time's supposed to heal ya
But I ain't done much healing

Hello, can you hear me
I'm here dreaming about who we used to be
When we were younger and free
I've forgotten how it felt before the world fell at our feet

There's such a difference between us
And a million miles

Hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home

Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

Hello, how are you?
It's so typical of me to talk about myself I'm sorry
I hope that you're well
Did you ever make it out of that town where nothing ever happened

It's no secret that the both of us
Are running out of time

So hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home
Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

Ooooohh, anymore
Ooooohh, anymore
Ooooohh, anymore
Anymore

Hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home
Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int par[N], diameter[N];
vector<int> edge[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  par[u] = v;
  diameter[v] = max(max(diameter[v], diameter[u]), (diameter[v] + 1)/2 + (diameter[u] + 1)/2 + 1);
}

bool done[N];
int seb[N], d[N];

int dfs(int now, int bef) {
  done[now] = 1;
  seb[now] = bef;
  int ans = d[now], at = now;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    d[it] = d[now] + 1;
    int far = dfs(it, now);
    if (d[far] > ans) {
      ans = d[far];
      at = far;
    }
  }
  return at;
}

int main() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
  }

  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    par[find(a)] = find(b);

    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (done[i]) continue;
    int far = dfs(i, -1);
    d[far] = 0;
    int farthest = dfs(far, -1);
    int diam = d[farthest];
    diameter[find(i)] = diam;
  }

  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int u;
      scanf("%d", &u);
      printf("%d\n", diameter[find(u)]);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      if (find(a) != find(b)) {
        merge(a, b);
      }
    }
  }
  return 0;
}
