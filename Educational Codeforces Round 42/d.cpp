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

#define int long long

using namespace std;

map<long long, set<int>> pos;
set<long long> kem;
set<pair<int, long long>> a; 

void add(int i, long long v) {
  pos[v].insert(i);
  a.insert(make_pair(i, v));
  if (pos[v].size() == 2) kem.insert(v);
}

void remove(int i) {
  long long v = (a.lower_bound(make_pair(i, -1)))->second;
  pos[v].erase(i);
  a.erase(make_pair(i, v));
  if (pos[v].size() == 1) kem.erase(v);
}

main() {
  int n;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%lld", &v);
    add(i, v);
  }
  while (!kem.empty()) {
    auto smallest = kem.begin();
    long long num = *smallest;
    //printf("hapus %lld\n", num);
    assert(pos[num].size() >= 2);
    auto idx_l = pos[num].begin();
    auto idx_r = idx_l;
    idx_r++;
    int l = *idx_l;
    int r = *idx_r;
    remove(l);
    remove(r);
    add(r, num * 2LL);
  }
  printf("%d\n", a.size());
  for (auto it : a) printf("%lld ", it.second);
  return 0;
}
