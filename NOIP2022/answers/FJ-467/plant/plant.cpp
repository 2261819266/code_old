#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int T,id;
int n,m,c,f;
bool matrix[1005][1005];
long long pre[1005][1005];
long long pre1[1005][1005]; 
long long rc,rf;
void calc_result(int x,int y){
	long long curc = 0,curf = 0;
	int x1 = x+2;
	if(matrix[x+1][y])return ;
	while(matrix[x1][y] == 0&&x1<=n){
		curc+=(pre[x][y]-1)*(pre[x1][y]-1);
		curf+=(pre[x][y]-1)*(pre[x1][y]-1)*(pre1[x1][y]-1);
		curc%=MOD;
		curf%=MOD;
		x1++;
	}
	rc+=curc;
	rc%=MOD;
	rf+=curf;
	rf%=MOD;
	return ;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while(T--){
		rc = rf = 0;
		memset(pre,0,sizeof(pre));
		memset(pre1,0,sizeof(pre1));
		memset(matrix,0,sizeof(matrix));
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i = 1;i<=n;i++){
			getchar();
			for(int j = 1;j<=m;j++){
				char c = getchar();
				matrix[i][j] = (c-0x30);
			}
		}
		for(int i = n;i>=1;i--){
			for(int j = m;j>=1;j--){
				if(!matrix[i][j]){
					pre[i][j] = pre[i][j+1]+1;
					pre1[i][j] = pre1[i+1][j]+1;
				}else{
					pre[i][j] = 0;
					pre1[i][j] = 0;
				}	
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				if(pre[i][j]){
					calc_result(i,j);
				}
			}
		}
		printf("%lld %lld\n",c*rc,f*rf);
	}
	return 0;
}
/*
�����Ӷ�Ӧ����O(TNM)
C�����뷨�ˣ�����˵��������pre[i][j]��ʾ��i�е�j�к����ж��ٸ�������0
���ҵ�һ��f[x][y]=0�ĵ���ΪC�����Ͻǣ�Ȼ��x++����f[x1][y]Ϊ���½ǣ�ֱ��f[x][y]Ϊ1�����
Ҫע��x1>x+1 
����ÿһ�еģ�C����������(pre[x][y]-1)(pre[x1][y]-1) 
C�ɹ��ˣ����� 
F����ʵ����C���ټӼ��о�����
Ҳ���������ٶ���һ��pre1[i][j]��ʾ��i�е�j�������ж��ٸ�������0
������C��������ʱ����(pre[x][y]-1)(pre[x1][y]-1)���ٳ���(pre1[x1][y]-1)���� 
9:25 T1 ��������ͨ���������� 
����100pts 
*/
