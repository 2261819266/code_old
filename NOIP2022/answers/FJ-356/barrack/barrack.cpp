#include <bits/stdc++.h>
#define ps(x) puts(#x)
#define gc getchar
#define pc putchar
#define R register
#define foru(i,j,k) for(register int i=j;i<=k;++i)
#define ford(i,j,k) for(register int i=j;i>=k;--i)
#define ll long long
using namespace std;
inline ll rd(){R char ch=gc();R ll s=0,f=1;while(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=gc();}return s*f;}
inline void print(ll x){if(x<0)pc('-'),x=-x;if(x>9)print(x/10);pc(x%10+48);}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	n=rd(),m=rd();
	if(n==m)ps(n);
	else ps(1);
	return 0;
}