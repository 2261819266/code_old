#include <bits/stdc++.h>
using namespace std;
const int mod_=998244353;
bool b[1000][1000];
short nor[1000][1001],nod[1001][1000];//norÿһ�����һ�����ڴ洢��ǰλ�� ��nodÿһ�����һ�����ڴ��浱ǰλ�� 
int t,id,n,m,c,f,vc,vf,x,y,z;
int find_right(int j,int k){//�ҿ�������Ҳࣩ   
	for(int l=0;l<nor[j][1000];l++){//��j����k�Ҳ�ĵ�һ���� 
		//cout << nor[j][l] << endl;
		if(nor[j][l]>k){
			return nor[j][l]-k; 
		}
	}
	return m-k;
}
int find_down(int j,int k){//�ҿ�������·���  
	for(int l=0;l<nod[1000][k];l++){//��j����k�·��ĵ�һ���� 
		//cout << nod[l][k] << endl;
		if(nod[l][k]>j){
			return nod[l][k]-j; 
		}
	}
	return n-j;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	char a;
	for (int i=0;i<t;i++){
		//��ʼ�������� 
		vc=0,vf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				cin >> a;
				if(a=='1'){
					b[j][k]=true; 
					nor[j][nor[j][1000]]=k;
					nod[nod[1000][k]][k]=j;
					nor[j][1000]++;
					nod[1000][k]++;
				}else{
					b[j][k]=false;
				}
			}
		}
		if(c==0&&f==0){//����ˮ1�� 
			cout << 0 << " " << 0 << endl;
			continue;
		}
		//C������
		for(int j=0;j<n-2;j++){//������һ�к͵ڶ��в����ܲ����Ϸ��ĵ�λ��C�����Ͻǣ� 
			for(int k=0;k<m-1;k++){
				if(b[j][k]==0&&b[j][k+1]==0&&b[j+1][k]==0){//�ж��Ϸ���C��λ
					x=find_down(j,k);
					y=find_right(j,k)-1;
					//cout << y << "+++++++++" << endl;
					for (int l=2;l<x;l++){
						z=find_right(j+l,k)-1;
						//cout << z << endl;
						vc+=y*z;
						vc=vc%mod_;
					}
				}
			}
		}
		cout << vc << " ";
		//F������ 
		if(f==0){//���� 
			cout << 0 << endl;
			continue;
		} 
		for(int j=0;j<n-3;j++){//������һ�к͵ڶ��в����ܲ����Ϸ��ĵ�λ��F�����Ͻǣ� 
			for(int k=0;k<m-1;k++){
				if(b[j][k]==0&&b[j][k+1]==0&&b[j+1][k]==0&&b[j+2][k]==0&&b[j+3][k]==0){//�ж��Ϸ���F��λ
					x=find_down(j,k);
					y=find_right(j,k)-1;
					//cout << y << "+++++++++" << endl;
					for (int l=2;l<x-1;l++){
						vf+=y*(find_right(j+l,k)-1)*(x-1-l);
						vf=vf%mod_;
					}
				}
			}
		}
		cout << vf << endl;
		//������ʱ�临�Ӷ�QAQ 
	}
	return 0;
}
