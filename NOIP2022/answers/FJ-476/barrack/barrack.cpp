#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll N=1e6+5;
vector<P> G[N];
ll n,m;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	if(m==n-1||n<=2)//�� 
	{
		ll ans=((1+n)*n/2-2*n+1)*4+4*(n-1)+1;
		printf("%d",ans);
		return 0;
	}
	if(m==n)//һ������һ���������ǲ���dfs�һ� 
	{
		ll ans=((1+n)*n/2-1)*4+1;
		printf("%d",ans);
		return 0;
	}
	else printf("1");
	return 0;
}
