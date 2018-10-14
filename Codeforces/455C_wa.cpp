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

int par[N], center[N];
vector<int> num[N], edge[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  int cu = center[u];
  int cv = center[v];
  for (int i = 0; i < 1; i++) {
    num[cv].push_back(num[cu][i] + 1);
    num[cu].push_back(num[cv][i] + 1);
  }
  sort(num[cu].begin(), num[cu].end());
  sort(num[cv].begin(), num[cv].end());
  reverse(num[cu].begin(), num[cu].end());
  reverse(num[cv].begin(), num[cv].end());
  par[u] = v;
  // printf("root %d dan %d: %d %d\n", u, v, num[cu][0] + num[cu][1], num[cv][0] + num[cv][1]);
  int diameter_u = num[cu][0] + num[cu][1];
  int diameter_v = num[cv][0] + num[cv][1];
  if (diameter_u > diameter_v) {
    center[v] = center[u];
  } else if (diameter_u == diameter_v && abs(num[cu][0] - num[cu][1]) < abs(num[cv][0] - num[cv][1])) {
    center[v] = center[u];
  }
  while (num[center[v]].size() > 2) {
    num[center[v]].pop_back();
  }
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
    par[i] = center[i] = i;
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
    int diameter = d[farthest];
    int radius = diameter / 2;
    for (int j = 0; j < radius; j++) farthest = seb[farthest];
    // printf("center %d: %d %d\n", farthest, diameter, radius);
    center[find(i)] = farthest;
    num[farthest].push_back(radius);
    num[farthest].push_back(diameter - radius);
  }

  // for (int i = 1; i <= n; i++) {
  //   if (find(i) == i) {
  //     printf("%d: %d %d\n", center[find(i)], num[center[find(i)]][0], num[center[find(i)]][1]);
  //   }
  // }
  // printf("\n");

  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int u;
      scanf("%d", &u);
      u = find(u);
      printf("%d\n", num[center[u]][0] + num[center[u]][1]);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      if (find(a) != find(b)) {
        merge(a, b);
      }
    }
    // for (int i = 1; i <= n; i++) {
    //   if (find(i) == i) {
    //     printf("%d: %d %d\n", center[find(i)], num[center[find(i)]][0], num[center[find(i)]][1]);
    //   }
    // }
    // printf("\n");
  }
  return 0;
}
