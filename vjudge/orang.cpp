#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int root[N],lc[N*300],rc[N*300];
int fa[N],deep[N],bl[N],son[N],id[N],cnt;
long long k[N*300],b[N*300],sum[N*300];
int front[N],nxt[N*2],to[N*2],tot;
long long A,B,QA,QB,ans;
int QL,QR;
int sum_chan,now,n,m;
int read()
{
	int x=0;
  scanf("%d", &x);
	return x;
}
struct  TREE
{
	long long get_sum(long long kk,long long bb,int n)
	{
		return (bb+bb+kk*(n-1))*n/2;
	}
	void change(int y,int &x,int l,int r)
	{
		x=++tot;
		lc[x]=lc[y];
		rc[x]=rc[y];
		k[x]=k[y];
		b[x]=b[y];
		sum[x]=sum[y];
		if(l>=QL&&r<=QR)
		{
			sum[x]+=get_sum(QB,(l-QL)*QB+QA,r-l+1);
			k[x]+=QB;
			b[x]+=(l-QL)*QB+QA;
			return;
		}
		int ll=max(QL,l),rr=min(QR,r);
		sum[x]+=get_sum(QB,QA+QB*(ll-QL),rr-ll+1);
		int mid=l+r>>1;
		if(QL<=mid) change(lc[y],lc[x],l,mid);
		if(QR>mid) change(rc[y],rc[x],mid+1,r);
	}
	void query(int x,int l,int r)
	{
		if(!x) return;
		if(QL<=l&&QR>=r)
		{
			ans+=sum[x];
			return;
		}
		int ll=max(l,QL),rr=min(r,QR);
		ans+=get_sum(k[x],b[x]+k[x]*(ll-l),rr-ll+1);
		int mid=l+r>>1;
		if(QL<=mid) query(lc[x],l,mid);
		if(QR>mid) query(rc[x],mid+1,r);
	}
}Tree;
struct CHAIN
{
	void add(int u,int v)
	{
		to[++tot]=v; nxt[tot]=front[u]; front[u]=tot;
		to[++tot]=u; nxt[tot]=front[v]; front[v]=tot;
	}
	void dfs1(int x,int f)
	{
		son[x]++;
		for(int i=front[x];i;i=nxt[i])
		 if(to[i]!=f)
		 {
		 	fa[to[i]]=x;
		 	deep[to[i]]=deep[x]+1;
		 	dfs1(to[i],x);
		 	son[x]+=son[to[i]];
		 }
	}
	void dfs2(int x,int top)
	{
		id[x]=++cnt;
		bl[x]=top;
		int y=0;
		for(int i=front[x];i;i=nxt[i])
		  if(to[i]!=fa[x]&&son[to[i]]>son[y])  y=to[i];
		if(!y) return;
		dfs2(y,top);
		for(int i=front[x];i;i=nxt[i])
		 if(to[i]!=fa[x]&&to[i]!=y) dfs2(to[i],to[i]);
	}
	int LCA(int x,int y)
	{
		while(bl[x]!=bl[y])
		{
			if(deep[bl[x]]<deep[bl[y]]) swap(x,y);
			x=fa[bl[x]];
		}
		if(deep[x]>deep[y]) return y;
		return x;
	}
	void change(int x,int y,int dis)
	{
		int l=0,r=dis;
		while(bl[x]!=bl[y])
		{
			if(deep[bl[x]]>deep[bl[y]])
			{
				QL=id[bl[x]];  QR=id[x];
				QA=A+(l+QR-QL)*B;
				QB=-B;
				Tree.change(root[sum_chan],root[sum_chan],1,n);
				x=fa[bl[x]];
				l+=QR-QL+1;
			}
			else
			{
				QL=id[bl[y]]; QR=id[y];
				QA=A+(r-(QR-QL))*B;
				QB=B;
				Tree.change(root[sum_chan],root[sum_chan],1,n);
				y=fa[bl[y]];
				r-=QR-QL+1;
			}
		}
		if(deep[x]<deep[y])
		{
			QL=id[x]; QR=id[y];
			QA=A+l*B;
			QB=B;
			Tree.change(root[sum_chan],root[sum_chan],1,n); 
		}
		else
		{
			QL=id[y]; QR=id[x];
			QA=A+r*B;
			QB=-B;
			Tree.change(root[sum_chan],root[sum_chan],1,n);
		}
	}
	void query(int x,int y)
	{
		while(bl[x]!=bl[y])
		{
			if(deep[bl[x]]<deep[bl[y]]) swap(x,y);
			QL=id[bl[x]]; QR=id[x];
			Tree.query(root[now],1,n);
			x=fa[bl[x]];
		}
		if(deep[x]>deep[y]) swap(x,y);
		QL=id[x]; QR=id[y];
		Tree.query(root[now],1,n);
	}
}Chain;
int main()
{
/*freopen("data.txt","r",stdin);
	freopen("my.txt","w",stdout);*/
  //puts("jembut");
	n=read(); m=read();
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		Chain.add(u,v);
	}
	Chain.dfs1(1,0);
	Chain.dfs2(1,1);
	tot=0;  char ch[3]; int dis;
	while(m--)
	{
		scanf("%s",ch);
		if(ch[0]=='c')
		{
			root[++sum_chan]=root[now];
			u=read(); v=read(); A=read(); B=read();
			u=(u+ans)%n+1; v=(v+ans)%n+1;
			dis=deep[u]+deep[v]-2*deep[Chain.LCA(u,v)];
			Chain.change(u,v,dis);
			now=sum_chan;
		}
		else if(ch[0]=='q')
		{
			u=read(); v=read();
			u=(u+ans)%n+1; v=(v+ans)%n+1;
			ans=0;
			Chain.query(u,v);
			printf("%lld\n",ans);
		}
		else
		{
			u=read();
			u=(u+ans)%(sum_chan+1);
			now=u;
		}
	}
} 