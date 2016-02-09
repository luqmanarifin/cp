#include <bits/stdc++.h>

using namespace std;

int f( int x , int y )
{
    if(y > x) swap(x, y);
    int delta = x - y;

    if( y > delta )
        return 2 * ( ( y - delta ) / 3 ) + delta;
    else
        return delta - 2 * ( ( delta - y ) / 4 );
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int ax, ay, ix, iy, h;
    scanf("%d %d %d %d %d", &ax, &ay, &ix, &iy, &h);
    int ret = f(abs(ax - ix), abs(ay - iy));
    if(ret > h) {
      puts("-1");
    } else {
      printf("%d\n", ret);
    }
  }
  
  return 0;
}
