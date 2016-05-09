#include <bits/stdc++.h>
using namespace std;
long long sawah[1010][1010],n,m,a,b,c,d,kasus; char kode[10]; bool kagebunshin[1010][1010],cekcek(true); long long ps[1010],ss[1010],haha;
void flow(long long x, long long y)
{
	if ((x<=c) && (x>=a) && (y<=d) && (y>=b) && (!kagebunshin[x][y]))
	{
		kagebunshin[x][y]=true;
		//cekcek=true;
		if (sawah[x+1][y]<sawah[x][y])
		{
			flow(x+1,y);
		}
		if (sawah[x-1][y]<sawah[x][y])
		{
			flow(x-1,y);
		}
		if (sawah[x][y+1]<sawah[x][y])
		{
			flow(x,y+1);
		}
		if (sawah[x][y-1]<sawah[x][y])
		{
			flow(x,y-1);
		}
		/*
		if (sawah[x+1][y+1]<=sawah[x][y]) flow(x+1,y+1);
		if (sawah[x-1][y+1]<=sawah[x][y]) flow(x-1,y+1);
		if (sawah[x+1][y-1]<=sawah[x][y]) flow(x+1,y-1);
		if (sawah[x-1][y-1]<=sawah[x][y]) flow(x-1,y-1);
		*/
	}
	else return;
}

int main()
{
	scanf("%s",kode);
	scanf("%lld %lld %lld",&n,&m,&kasus);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%lld",&sawah[i][j]);
		}
	}
	//if (n==1)
	if ((kode[0]=='.') && (kode[1]=='.') && (kode[2]=='.') && (kode[3]=='.') && (kode[4]=='.') && (kode[5]=='5') && (kode[6]=='6'))
	{
		for (int i=1;i<=m;i++)
		{
			if (sawah[1][i]>sawah[1][i+1])
			{
				ps[i]=ps[i-1]+1;
			}
		}
		for (int i=m;i>=1;i++)
		{
			if (sawah[1][i]>sawah[1][i-1])
			{
				ss[i]=ss[i+1]+1;
			}
		}
		for (int k=1;k<=kasus;k++)
		{
			scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
			if (ps[d-1]-ps[b-1]==d-b)
			{
				printf("Kiri Atas\n");
			}
			else if (ss[b+1]-ss[d+1]==d-b)
			{
				printf("Kanan Bawah\n");
			}
			else
			{
				printf("Tidak Mungkin\n");
			}
		}
	}
	else
	{
		for (int k=1;k<=kasus;k++)
		{
			memset(kagebunshin,false,sizeof(kagebunshin));
			cekcek=true;
			scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
			flow(a,b);
			for (int i=a;i<=c;i++)
			{
				for (int j=b;j<=d;j++)
				{
					if (kagebunshin[i][j]==false)
					{
						cekcek=false;
					}
				}
			}
			if (cekcek)
			{
				printf("Kiri Atas\n");
			}
			else
			{
				memset(kagebunshin,false,sizeof(kagebunshin));
				flow(c,d);
				cekcek=true;
				for (int i=a;i<=c;i++)
				{
					for (int j=b;j<=d;j++)
					{
						if (kagebunshin[i][j]==false)
						{
							cekcek=false;
						}
					}
				}
				if (cekcek)
				{
					printf("Kanan Bawah\n");
				}
				else
				{
					printf("Tidak Mungkin\n");
				}
			}
		}
	}
	return 0;
}