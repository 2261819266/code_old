#include<bits/stdc++.h>
using namespace std;

int a[1100][1100];

int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	cin>>t>>id;
	while(t--) {
		int n,m,c,f;//��������x,y��ƽ��ֱ������ϵx,y�෴
		cin>>n>>m>>c>>f;//m=x��,n=y��(�����߼�) 
		for(int i = 0; i < n; i++) { //�� 
			cin.get();
			for(int j = 0; j < m; j++) { //�� 
				a[j][i] = cin.get()-'0';
			}
		}
		if(c==0&&f==0){
			cout<<0<<" "<<0<<endl; 
			continue;
		}
		int ansc=0,ansf=0;
		//c----------
		for(int x1 = 0; x1<m-1; x1++) { //��j��
			for(int y1 = 0; y1<n; y1++) { //��i��
				for(int y2 = y1+2; y2<n; y2++) { //��i��
					if(a[x1][y1]==1||a[x1][y2] == 1){
						continue;
					} 
					bool flag = false;
					for(int i = y1;i<=y2;i++){
						if(a[x1][i] == 1){
							flag = true;
							break;
						} 
					} 
					if(flag){
						continue;
					}
					int xa=0,xb=0,ya=0;
					for(int i = x1+1;i<m;i++){
						if(a[i][y1] == 1){
							break;
						}else{
							xa++;
						}
					}
					for(int i = x1+1;i<m;i++){
						if(a[i][y2] == 1){
							break;
						}else{
							xb++;
						}
					}
					for(int i = y2+1;i<n;i++){
						if(a[x1][i] == 1){
							break;
						}else{
//							cout<<666<<endl;
							ya++;
						}
					}
//					cout<<xa<<" "<<xb<<" "<<ya<<endl;
					ansc += xa*xb;
					ansf += (xa*xb)*ya;
//					cout<<"---"<<ansf<<endl;
					ansc %= 998244353;
					ansf %= 998244353;
				}
			}
		}
		
		cout<<ansc*c%998244353<<" "<<ansf*f%998244353<<endl;
	}
	return 0;

}
