#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,f,id;
char k[1020][1020],z[1020];
long long ansc,ansf,mod=998244353,ans[1020][1020][2];
int main(){
   freopen("plant.in","r",stdin);
   freopen("plant.out","w",stdout);
   cin>>t>>id;
   while(t--){
   	 scanf("%d%d%d%d",&n,&m,&c,&f);ansc=0;ansf=0;
   	 for(int i=1;i<=n;i++){
   	 	cin>>z;
   	 	for(int j=1;j<=m;j++)k[i][j]=z[j-1];
	 }
	 for(int i=1;i<=n;i++){
	 	for(int j=m;j>=0;j--){
	 		ans[i][j][0]=ans[i][j][1]=0;
		}
	 }
	 for(int i=1;i<=n;i++){
	 	int g=0;
	 	for(int j=m;j>=1;j--){
	 		if(k[i][j]=='1'){
	 			g=0;
			}
			else{
				ans[i][j][0]=g;//�Ҳ��ܽ��ж��ٲ���չ 
				g++;
			}
		}
	 }
	 for(int i=1;i<=m;i++){
	 	int g=0;
	 	for(int j=n;j>=1;j--){
	 		if(k[j][i]=='1'){
	 			g=0;
			}
			else{
				ans[j][i][1]=g;
				g++;
			}
		}
	 }
	 for(int i=1;i<=m;i++){
	 	long long all=0;
	 	for(int j=3;j<=n;j++){
	 		while((k[j][i]=='1'||k[j-1][i]=='1'||k[j-2][i]=='1')&&j<=n){
	 			all=0;j++;
			}
			if(j>n)break;
	 		all+=ans[j-2][i][0];
	 		all%=mod;
	 		ansc+=all*ans[j][i][0]%mod;ansc%=mod;//cout<<j<<' '<<i<<' '<<all*ans[j][i][0]%mod<<endl;
	 		ansf+=all*ans[j][i][0]%mod*ans[j][i][1]%mod;ansf%=mod;
		}
	 } 
	 printf("%lld %lld\n",ansc*c,ansf*f);
   }
   return 0;
}
/*
������ζԴ𰸽��м���
��Ȼ����ȷ�����Ժ���н��м���
ֻҪʹ��c�·�������չ�ͱ��f 
Ч��Ӧ�ÿ�����n^2 
*/ 


