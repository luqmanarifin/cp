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

template <typename t>
t getnum()
{
  t res=0, mult=1;
  char c;
  while(1) {
    c=getchar(); if(c==' ' || c=='\n') continue; else break;
  }
  if(c=='-') mult*=-1; else res+=c-'0';
  while(1) {
    c=getchar();
    if(c>='0' && c<='9') { res*=10; res+=c-'0'; }
    else break;
  }
  return res*mult;
} 

int main() {
  long long a = getnum<long long>();
  cout << a << endl;

  return 0;
}
