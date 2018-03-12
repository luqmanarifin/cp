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

multiset<int> s[N << 2];
multiset<int>::iterator pt[N << 2];
int a[N];
vector<int> st;

void build(int p, int l, int r) {
  for (int i = l; i <= r; i++) s[p].insert(-a[i]);
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
}

void change(int p, int l, int r, int at, int bef, int val) {
  //printf("niki %d %d %d: %d %d %d\n", p, l, r, at, bef, val);
  s[p].erase(s[p].find(-bef));
  s[p].insert(-val);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (at <= mid) {
    change(p + p, l, mid, at, bef, val);
  } else {
    change(p + p + 1, mid + 1, r, at, bef, val);
  }
}

void query(int p, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    st.push_back(p);
    return;
  }
  if (r < ll || rr < l) return;
  int mid = (l + r) >> 1;
  query(p + p, l, mid, ll, rr);
  query(p + p + 1, mid + 1, r, ll, rr);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      change(1, 1, n, l, a[l], r);
      a[l] = r;
    } else {
      st.clear();
      query(1, 1, n, l, r);
      priority_queue<pair<int, int>> pq;    // value - p nya dimana
      for (auto it : st) {
        pt[it] = s[it].begin();
        pq.emplace(-(*pt[it]), it);
      }
      bool found = 0;
      vector<int> v;
      for (int i = 0; i < 2 && !pq.empty(); i++) {
        v.push_back(pq.top().first);
        int it = pq.top().second;
        pq.pop();
        pt[it]++;
        if (pt[it] != s[it].end()) {
          pq.emplace(-(*pt[it]), it);
        }
      }
      while (!pq.empty() && !found) {
        v.push_back(pq.top().first);
        
        int sz = v.size();
        if (v[sz-3] < v[sz-2] + v[sz-1]) {
          found = 1;
          printf("%lld\n", (long long) v[sz-2] + v[sz-1] + v[sz-3]);
          break;
        }
        
        int it = pq.top().second;
        pq.pop();
        pt[it]++;
        if (pt[it] != s[it].end()) {
          pq.emplace(-(*pt[it]), it);
        }
      }
      if (!found) puts("0");
    }
  }

  return 0;
}
