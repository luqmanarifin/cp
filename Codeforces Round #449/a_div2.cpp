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

const int N = 105;

char s[N];

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s + 1);
  while (m--) {
    int l, r;
    char a, b;
    scanf("%d %d %c %c", &l, &r, &a, &b);
    for (int i = l; i <= r; i++) if (s[i] == a) s[i] = b;
  }
  printf("%s\n", s + 1);
  return 0;
}
