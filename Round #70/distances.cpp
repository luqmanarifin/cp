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

const int N = 105;
const int inf = 1e9;

int d[N][N], a[N * N], b[N * N], c[N * N];
int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", a + i, b + i, c + i);
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
    merge(a[i], b[i]);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (d[a[i]][b[i]] != c[i]) {
      puts("-1");
      return 0;
    }
  }
  vector<int> mst;
  for (int i = 1; i <= n; i++) {
    if (find(i) != find(1)) {
      mst.push_back(i);
      merge(i, 1);
    }
  }
  printf("%d\n", m + mst.size());
  for (int i = 0; i < m; i++) printf("%d %d %d\n", a[i], b[i], c[i]);
  for (auto it : mst) printf("%d %d %d\n", 1, it, 1);
  return 0;
}
