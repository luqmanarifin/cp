/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

int h1, a1, c1, h2, a2;
int attacks;

bool can(int heal) {
  attacks = 0;
  int hku = h1, hmu = h2;
  for (int i = 0; i < heal; i++) {
    hku += c1;
    hku -= a2;
  }
  while (1) {
    attacks++;
    hmu -= a1;
    if (hmu <= 0) return 1;
    hku -= a2;
    if (hku <= 0) return 0;
  }
  assert(0);
}

int main() {
  scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
  int l = 0, r = 1000000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  can(l);
  printf("%d\n", l + attacks);
  for (int i = 0; i < l; i++) puts("HEAL");
  for (int i = 0; i < attacks; i++) puts("STRIKE");
  return 0;
}
