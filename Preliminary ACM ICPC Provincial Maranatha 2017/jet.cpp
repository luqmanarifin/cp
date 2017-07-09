#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x,y,z;
		int x1,y1,x2,y2,j;
		scanf("%d%d%d", &x,&y,&z);
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &j);
		if (x1 > x2) swap(x1,x2);
		if (y1 > y2) swap(y1,y2);
		if (x1 <= x && x <= x2 &&
		    y1 <= y && y <= y2 &&
		    z <= j) {
			puts("shoot");
		}
		else puts("hold");
	}
	return 0;
}
