#include <bits/stdc++.h>
#define ps(x) puts(#x)
#define foru(i,j,k) for(register int i=j;i<=k;++i)
#define ford(i,j,k) for(register int i=j;i>=k;--i)
#define gc getchar
#define pc putchar
#define R register
#define ll long long
using namespace std;
const ll md = 998244353;
inline ll rd(){R char ch=gc();R ll s=0,f=1;while(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=gc();}return s*f;}
inline void print(ll x){if(x<0)pc('-'),x=-x;if(x>9)print(x/10);pc(x%10+48);}
////////////////////////////////////////
int t,id;
int n,m,c,f;
int a[1005][1005];
int wz[1005][1005];//�� i ���� 1 ���±�
int mx[1005];//ÿһ�����һ�� 1 �±� 
int gs[1005];//��һ�� 1 ���� 
ll sum[1005][1005];
ll cc,ff;
string s;
inline void cntc()
{
	foru(l,1,m-1)//ÿһ�����ҵ������������ϵ� 0 
	{
		foru(i,1,n-2)
		{
			foru(j,i+2,n)
			{
				if(sum[l][j]-sum[l][i-1]==0)//i~j ȫ�� 0
				{
					ll x,y;
					if(gs[i]==0||l>mx[i])x=m-l;
					else
					{
						//Ȼ����ͷβ���м��� 0
//						else
//						{
							x=wz[i][upper_bound(wz[i]+l-1,wz[i]+gs[i]+1,l)-wz[i]];
							while(a[i][x-1]==1)x--;
							//�ҵ������һ�� 1 ��λ�� 
							x=x-l-1;
							if(x<=0)continue;
						//}
					}
					if(gs[j]==0||l>mx[j])y=m-l;
					else
					{
//						else
//						{
							y=wz[j][upper_bound(wz[j]+l-1,wz[j]+gs[j]+1,l)-wz[j]];
							//�ҵ������һ�� 1 ��λ�� 
							while(a[j][y-1]==1)y--;
							y=y-l-1;
							if(y<=0)continue;
						//}
					}
					cc+=x*y;
					if(cc>=md)cc-=md;
				}
			}
		}
	}
}
inline void cntf()
{
	foru(l,1,m)//ÿһ�����ҵ������������ϵ� 0 
	{
		foru(i,1,n)
		{
			foru(k,i+3,n)
			{
				foru(j,i+1,k-1)
				{
					if(sum[l][k]-sum[l][i-1]==0)//i~j ȫ�� 0
					{
						ll x,y;
						if(gs[i]==0||l>mx[i])x=m-l;
						else
						{
							//Ȼ����ͷβ���м��� 0
//							else
//							{
								x=wz[i][upper_bound(wz[i]+l-1,wz[i]+gs[i]+1,l)-wz[i]];
								while(a[i][x-1]==1)x--;
								//�ҵ������һ�� 1 ��λ�� 
								x=x-l-1;
								if(x<=0)continue;
							//}
						}
						if(gs[j]==0||l>mx[j])y=m-l;
						else
						{
//							else
//							{
								y=wz[j][upper_bound(wz[j]+l-1,wz[j]+gs[j]+1,l)-wz[j]];
								//�ҵ������һ�� 1 ��λ�� 
								while(a[j][y-1]==1)y--;
								y=y-l-1;
								if(y<=0)continue;
							//}
						}
						ff+=x*y;
						if(ff>=md)ff-=md;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=rd(),id=rd();
	while(t--)
	{
		n=rd(),m=rd(),c=rd(),f=rd();
		foru(i,1,n)
		{
			cin>>s;
			mx[i]=0;
			gs[i]=0;
			foru(j,0,s.size()-1)
			{
				a[i][j+1]=s[j]^48;
				sum[j+1][i]=sum[j+1][i-1]+a[i][j+1];
				if(a[i][j+1]==1)
				{
					wz[i][++gs[i]]=j+1;
					mx[i]=j+1;
				}
			}
//			gs[i]++;
//			wz[i][gs[i]]=m+1;
		}
		if(c==0&&f==0)
		{
			pc(48),pc(' '),pc(48),ps();
			continue;
		}
		cc=0,ff=0;
		cntc();
		cntf();
		print(cc*c%md),pc(' '),print(ff*f%md),ps();
		//cntf();
	}
	return 0;
}
//1 0
//4 3 1 1
//001
//010
//000
//000
