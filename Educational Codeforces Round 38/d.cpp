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

const int N = 2e5 + 5;

// cost - node - ok
priority_queue<pair<long long, int>> pq;
vector<pair<int, long long>> edge[N];
long long a[N], d[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v; long long w;
    scanf("%d %d %lld", &u, &v, &w);
    w *= 2;
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    d[i] = a[i];
    pq.emplace(-a[i], i);
  }
  while (!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if (d[now] != cost) continue;
    for (auto it : edge[now]) {
      long long ncos = cost + it.second;
      int near = it.first;
      if (d[near] > ncos) {
        d[near] = ncos;
        pq.emplace(-d[near], near);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%lld ", d[i]);

  return 0;
}
