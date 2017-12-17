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

int size;
int bef[N], aft[N], len[N], num[N];
set<pair<int, int>> s;    // -panjang, dimana

bool valid(int i) {
  return 1 <= i && i <= size;
}

void remove(int at) {
  int be = bef[at];
  int af = aft[at];
  aft[be] = af;
  bef[af] = be;
  if (valid(be) && valid(af) && num[be] == num[af]) {
    s.erase(make_pair(-len[be], be));
    s.erase(make_pair(-len[af], af));
    len[be] += len[af];
    s.insert(make_pair(-len[be], be));
    remove(af);
  }
}

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j]) j++;
    size++;
    int id = size;
    len[id] = j - i + 1;
    num[id] = a[i];
    s.insert(make_pair(-len[id], id));
    i = j;
  }
  for (int i = 0; i <= size + 1; i++) {
    bef[i] = i - 1;
    aft[i] = i + 1;
  }
  int ans = 0;
  while (!s.empty()) {
    ans++;
    auto it = *(s.begin());
    s.erase(it);
    remove(it.second);
  }
  cout << ans << endl;
  return 0;
}
