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

const int N = 1e6 + 5;

bool is[N];
int p[N], to[N], from[N];
vector<int> edge[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p[i] = i;
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  set<pair<int, int>> s;
  s.insert(make_pair(4, 2));
  for (int i = 3; i < N; i++) {
    while (!s.empty() && (s.begin())->first == i) {
      auto it = s.begin();
      s.insert(make_pair(it->first + it->second, it->second));
      s.erase(it);
    }
    
    auto it = s.end();
    it--;
    to[i] = it->first;
    
    if (is[i] == 0) {
      s.insert(make_pair(i + i, i));
    }
  }
  for (int i = 3; i <= 20; i++) printf("%d %d\n", i, to[i]);
  fill(from, from + N, N);
  for (int i = 3; i < N; i++) {
    if (to[i] < N) {
      from[to[i]] = min(from[to[i]], i);
      edge[to[i]].push_back(i);
    }
  }
  int n;
  scanf("%d", &n);
  int ans = N;
  for (auto it : edge[n]) {
    printf("it %d\n", it);
    ans = min(ans, from[it]);
  }
  cout << ans << endl;
  return 0;
}
