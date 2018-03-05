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

int s[N], cnt[N];
int bit[N];

void upd(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] = max(bit[i], val);
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret = max(ret, bit[i]);
  return ret;
}

vector<int> lis(vector<int> a) {
  memset(bit, 0, sizeof(bit));
  vector<int> ret;
  for (auto it : a) {
    int val = find(it) + 1;
    upd(it, val);
    ret.push_back(val);
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    s[l]++;
    s[r + 1]--;
  }
  for (int i = 1; i <= m; i++) s[i] += s[i-1];
  vector<int> num, rnum;
  for (int i = 1; i <= m; i++) num.push_back(s[i]);
  rnum = num;
  reverse(rnum.begin(), rnum.end());
  //for (int i = 1; i <= m; i++) printf("%d ", cnt[i]); printf("\n");
  auto alis = lis(num);
  auto blis = lis(rnum);
  //for (auto it : alis) printf("%d ", it); printf("\n");
  //for (auto it : blis) printf("%d ", it); printf("\n");
  
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans = max(ans, alis[i] + blis[m - 1 - i] - 1);
  }
  cout << ans << endl;
  return 0;
}
