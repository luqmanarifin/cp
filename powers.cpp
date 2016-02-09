#include<cstdio>
main(){int i=-1,n;scanf("%d",&n);while(++i<31)if(n&(1<<i))printf("%d ",1<<i);} 