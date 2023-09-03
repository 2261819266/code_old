#include "bits/stdc++.h"
using namespace std;

int T;
int sta[310][4]; //ջ  1->ջ�� 0->ջ��Ԫ������ Ԫ�������� 
int nxt[2000010]; //ÿһ������һ�ų��ֵ�λ�� 
int now[310]; //����ÿһ�������ĸ�ջ
int op;
int stp[4000010][3]; //�ж���¼ 
int a[310]; //��ʱ��¼���� 
int b[2000010]; //������ 
int kon; //�ĸ�ջҪ���� 
int use0,use2;

int read() {
	char c=getchar();
	long long re=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') re=re*10+c-'0',c=getchar();
	return re; 
}

void delup(int p) { //ɾ��ջ��Ԫ�� 
	sta[p][0]--;
	if (stp[p][0]==0 && kon==-1) kon=p;
}

void deldown (int p) { //ɾ��ջ��Ԫ�� 
	sta[p][1]=sta[p][2];
	if (sta[p][0]==3) sta[p][2]=sta[p][3];
	sta[p][0]--;
}

void add(int p,int i) {
	sta[p][++sta[p][0]]=i;
	now[b[i]]=p;
}


int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	T=read();
	while (T--) {
		int n=read(),m=read(),k=read();
		op=0;
		memset(a,0,sizeof(a));
		memset(now,0,sizeof(now));
		memset(sta,0,sizeof(sta));
		for (int i=1;i<=m;i++) {
			b[i]=read();
			if (a[b[i]]==0) {
				a[b[i]]=i;
			} else {
				nxt[a[b[i]]]=i;
				nxt[i]=0;
				a[b[i]]=0;
			}
		}
		
		kon=n; 
		for (int i=1;i<=m;i++) {
			if (now[b[i]]!=0) { //����������ջ�ڣ���ôֱ������ 
				int p=now[b[i]];
				now[b[i]]=0;
				if (b[sta[p][sta[p][0]]]==b[i]) { //��ջ�� 
					stp[++op][0]=1,stp[op][1]=p;
					delup(p); 
				} else { //ջ�� 
					stp[++op][0]=1,stp[op][1]=kon;
					stp[++op][0]=2,stp[op][1]=p,stp[op][2]=kon;
					deldown(p);
				}
				continue;
			} 
			//����ջ�� 
			if (kon==-1) { //����û��Ԥ����λ 
				int tmp=-1;
				for (int j=1;j<=n;j++) {
					if (sta[j][0]==1) {
						if (tmp==-1) {
							tmp=j;
						} else {
							if (nxt[sta[j][1]]>nxt[sta[tmp][1]]) tmp=j;
							break;
						}
 					}
				}
				stp[++op][0]=1,stp[op][1]=tmp;
				add(tmp,i);
			} else {
				int tmp=-1;
				for (int j=n;j>=1;j--) {
					if (j==kon) continue;
					if (sta[j][0]==0 || sta[j][0]==1) {
						tmp=j;
						stp[++op][0]=1,stp[op][1]=tmp;
						add(tmp,i);
						break;
					}
				}
				if (tmp==-1) {
					for (int j=n;j>=1;j--) {
						if (nxt[sta[j][1]]<nxt[sta[j][2]]) {
							tmp=j;
							stp[++op][0]=1,stp[op][1]=tmp;
							add(tmp,i);
							break;
						} 
					}
					if (tmp==-1) {
						stp[++op][0]=1,stp[op][1]=tmp;
						add(tmp,kon);
						kon=-1;
					}
				}
			}
		}
		printf("%d\n",op);
		for (int i=1;i<=op;i++) {
			printf("%d ",stp[i][0]);
			for (int j=1;j<=stp[i][0];j++) printf("%d ",stp[i][j]);
			printf("\n");
		}
	}

	return 0;
}
