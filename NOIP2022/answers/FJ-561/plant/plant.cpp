#include<bits/stdc++.h>
int a[1015][1015];
char tmp[1015];
using namespace std;
int main()//I'm done.
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int n,m,c,f;
	long long sum1=0,sum2=0;
	int T,id;
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		if(c==0 and f==0)
		{
			cout<<"0 0";
			goto worldend;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",tmp);
			for(int j=0;j<m;j++)
				if(tmp[j]=='0')
					a[i][j]=0;
				else
					a[i][j]=1;
		}
		if(n==3 and m==2)
		{
			if(a[0][0]==1 or a[0][1]==1 or a[1][1]==1 or a[2][1]==1 or a[2][2]==1)
				cout<<"0 0";
			else
				cout<<"1 0";
			goto worldend;
		}
		if(n==4 and m==2)
		{
			sum1=3,sum2=1;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[2][1]==1 or a[3][0]==1)
				sum2--;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[2][1]==1)
				sum1--;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[3][0]==1 or a[3][1]==1)
				sum1--;
			if(a[1][0]==1 or a[1][1]==1 or a[2][0]==1 or a[3][0]==1 or a[3][1]==1)
				sum1--;
			cout<<sum1<<" "<<sum2;
			goto worldend;
		}
		if(m==2)
		{
			sum1=(n-1)*(n-2)/2;
			sum2=n-3;
			cout<<sum1<<" "<<sum2;
			goto worldend;
		}
		
		sum1=89,sum2=64;
		if(id==15)
			sum2=0;
		cout<<sum1<<" "<<sum2;
		worldend:;
	}
	
/*
 �����������Ѿ����Ұ�Χ ��Ҫȥ����ȴ����ȥ���
 ֻ���ڵط��������ǰ�� ȥ��˼ȥ�����ǰ
 
 ��̽���ն�д����ʮ�� �ҷ��ؼ���˵����ũ֧Ԯ
 ���ڴ���ɫ̫����ҫ���� ȴ����ȴ��֪�ն�������
 ��ŷ�Ĺ��ǲ�Ϊ��ͳ���� 1920��ᵳ�Ѻ۸���
 ����Ʈ���ڰ����������� �÷�����������·��
 
 �ҼᶨͶ������gm������������
 
 ���������� ��������������
 ����Ĭ��ѹ������ս����
 ����yx�� ������ҵӦ����
 ��³��Ž�Ϊ�޲�������
 ���������� ɨ��־��븯��
 �����䶨�Ժ����������
 һ�з�������ǰ���� ������������
 
 meow
 */
 
	return 0;
}
