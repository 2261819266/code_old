#include<bits/stdc++.h>
#define ll long long
#define fs(i,x,y,z) for(int i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(int i=x;i>=y;i+=z)
const ll N=1001,inf=998244353ll;
inline int read(){
	int v=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){v=v*10+(c-'0');c=getchar();}
	return v*w;
}
using namespace std;
int n,m,c,f,a[N][N],heng[N][N],shu[N][N];
ll presum[N];//heng[i][j]��a�����ǰ׺�ͣ�shu[i][j]��a�����ǰ׺�� 
char s[N];
void mian(){
	n=read(),m=read(),c=read(),f=read();
	//����ö�ٳ�ʼ�У�Ȼ���¼�ж���������������ɣ�
	//��ö���˳�ʼ�У�������ÿһ�д���һ�п�ʼ��������������÷ֶ� 
	//��𰸾���\sum_{i=1}^m \prod ÿһ�εķ�ʽ���������Onm����� 
	//�����C�࣬��ôF����ô����
	//�����������ڴ������±������������𰸾���(iΪ���½ǵ�C)\times (��i����ĵ�һ��1-1) 
	if(c==0&&f==0){
		puts("0 0");
		return;
	}
	fs(i,1,n,1) fs(j,1,m,1) heng[i][j]=shu[i][j]=a[i][j]=0; 
	fs(i,1,n,1) presum[i]=0;
	fs(i,1,n,1){
		//scanf("%s",s+1);
		fs(j,1,m,1){
			char ch=getchar();
			a[i][j]=ch-'0',heng[i][j]=heng[i][j-1]+a[i][j],shu[j][i]=shu[j][i-1]+a[i][j];//���е���� 
		}
		getchar();
	}
	ll ans=0;//�ܵĴ� 
	//ö��C��
	if(c){
		fs(col,1,m,1){//����ߵ�һ�������� 
			//=sumpre*ai��Ȼ������ټӵ�sumpre����ȥ
			ll res=0,curline=1;//sigma��ǰ��ai�ĺͣ�res������Ҫ��Ķ��� 
			fs(cur,1,n,1){
				if(a[cur][col]){curline=1;continue;}//��һ���Σ�Ҫ�ؿ��� 
				int pos=upper_bound(heng[cur]+1,heng[cur]+m+1,heng[cur][col])-heng[cur];//�Һ���ĵ�һ��1 
				int fas=max(pos-col-1,0);//������Щ�������õ�
		//		printf("for(%d,%d),pos is (%d,%d),place as %d\n",cur,col,cur,pos,fas);
				(res+=presum[max(curline-2,0ll)]*fas%inf)%=inf;
			//	sigma+=fas; 
				presum[curline]=presum[curline-1]+fas;curline++;
			} 
		//	printf("curline at here is %d\n",res);
			(ans+=res)%=inf;//��һ�еĴ� 
		} 
		printf("%lld ",ans);ans=0;
	}else printf("0 ");
	if(f){
		fs(i,1,n,1) presum[i]=0;
		//�������ǿ���F�� 
		fs(col,1,m,1){//FҲҪ���������������� 
			ll res=0,curline=1;
			fs(cur,1,n,1){//��ǰ�� 
				if(a[cur][col]){curline=1;continue;}//�����ˣ��ؿ� 
				int posi=upper_bound(shu[col]+1,shu[col]+n+1,shu[col][cur])-shu[col];
				int pos=upper_bound(heng[cur]+1,heng[cur]+m+1,heng[cur][col])-heng[cur];//�Һ���ĵ�һ��1 
				int fas=max(pos-col-1,0);
				//��������Ϊ��β
			//	printf("(%d,%d) contributes %d,posi is %d\n",cur,col,presum[max(curline-2,0)]*fas*max(0,posi-cur-1),posi);
				(res+=presum[max(curline-2,0ll)]*fas%inf*max(0,posi-cur-1)%inf)%=inf;
				presum[curline]=presum[curline-1]+fas;curline++; 
			}
		//	printf("curline at here is %d\n",res);
			(ans+=res)%=inf;
		}
		printf("%lld\n",ans);
	}else puts("0");
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t=read(),id=read();while(t--) mian();
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
//����Ҫ��x1+1<x2���������ٵÿ�һ��
//Ҫ��Ҫ���߶���ά��������ǰ׺�ͼ��ɰ� 
