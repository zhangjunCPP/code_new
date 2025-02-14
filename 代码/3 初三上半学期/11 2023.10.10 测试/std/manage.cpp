
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e6+5;
int n,m,lst[N],ans[N];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=m;x+=lowbit(x))
			c[x]+=v;
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline int query(int l,int r)
	{
		return query(r)-query(l-1);
	}
}sm;

signed main()
{
	
	 freopen("manage.in","r",stdin);
	 freopen("manage.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read();
		if(!lst[x])
			ans[n]++;
		else
		{
			ans[sm.query(i-1)-sm.query(lst[x])]++;
			sm.add(lst[x],-1);
		}
		sm.add(i,1);lst[x]=i;
	}
	for(int i=n-1;i>=1;--i)
		ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i)
		write(ans[i]),putchar(' ');
	return 0;
}
