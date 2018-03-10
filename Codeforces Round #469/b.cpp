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
const int lim = 100;

long long a[N];

int main() {
  long long n;
  int q;
  scanf("%lld %d", &n, &q);
  while (q--) {
    long long x;
    scanf("%lld", &x);
    //printf("NIKI TANYA %lld\n", x);
    x--;
    long long ada = n, st = 0;
    long long lompat = 2;
    bool found = 0;
    long long done = 0;
    
    int shift = 0;
    long long start = 0;
    while (ada > 0) {
      //printf("%lld %lld\n", ada, st);
      long long it = start + (st << shift);
      start += ((st ^ 1) << shift);
      //printf("starting from %lld\n", it);
      if (x >= it && x % lompat == it % lompat) {
        done += (x - it) / lompat + 1;
        found = 1;
        break;
      }
      
      long long take = ada / 2 + ((ada % 2) && (st == 0));
      st = (st ^ (ada % 2));
      ada -= take;
      done += take;
      lompat *= 2;
      shift++;
    }
    printf("%lld\n", done);
  }
  return 0;
}
