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
 
int bit[N], a[N];
long long s[N];
 
void add_bit(int i, int v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}
 
void add(int l, int r) {
  add_bit(l, 1);
  add_bit(r + 1, -1);
}
 
int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}
 
long long find(int l, int r) {
  return l <= r? s[r] - s[l - 1] : 0;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) bit[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
      int l = 1, r = i - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (find(mid + 1, i - 1) <= a[i]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (l == r) add(l, i - 1); //, printf("kiri %d %d\n", l, i);
      
      l = i + 1, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (find(i + 1, mid - 1) <= a[i]) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (l == r) add(i + 1, l); //, printf("kanan %d %d\n", i, l);
    }
    
    for (int i = 1; i <= n; i++) printf("%d ", find(i)); printf("\n");
  }
 
  return 0;
}