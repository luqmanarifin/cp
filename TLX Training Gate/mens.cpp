#include <bits/stdc++.h>
using namespace std;
long gcf(int x,int y)
{
	long r;
	if (y==0)
	{
		r=x;
	}
	else 
	{
		r=gcf(y,x%y);
	}
	return r;
}

int main()
{
	long long a,b,c,d,e,f,g,k;
	scanf("%lld %lld",&a,&b);
	scanf("%lld %lld",&c,&d);
	e=a*d;
	f=b*c;
	g=b*d;
	e+=f;
	k=gcf(e,g);
	e=e/k;
	g=g/k;
	printf("%lld %lld\n",e,g);
	return 0;
}