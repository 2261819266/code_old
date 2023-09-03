#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p;
int op[2000005][3];
int a[2000005];
void f(){
	queue<int> t[1005];
	int w[1005] = {0};
	int num[305] = {0};
	deque<int>adj[305];
	for(int i = 1;i<=m;i++){
		if(!w[a[i]]){
			w[a[i]]++;
			t[a[i]].push(i);
			adj[1].push_back(a[i]);
			op[p][0] = op[p][1] = 1;
			p++;
//			cout<<a[i]<<"push into the first deque"<<adj[1].front()<<endl;
		}else{
			w[a[i]]--;
			if(a[i] == adj[1].back()){
				op[p][0] = op[p][1] = 1;
				p++;
//				cout<<a[i]<<"and the top of the first deque pop!"<<endl;
				t[a[i]].pop();
				adj[1].pop_back();
				continue;
			}
			int j = 2;
			for(;j<=n;j++){
				if(t[a[i]].front()>num[j]){
					adj[j].push_back(a[i]);
					num[j] = t[a[i]].front();
					op[p][0] = 1;
					op[p][1] = j;
					p++;
//					cout<<a[i]<<"push into the "<<j<<"th. deque"<<endl;
//					cout<<adj[j].front()<<" "<<adj[1].front()<<endl;
					break;
				}
			}
//			if(j == n+1){
//				for(int k = 1;k<=n;k++){
//					cout<<adj[k].size()<<" ";
//				}
//				cout<<endl;
//				for(int k = 1;k<=n;k++){
//					cout<<num[k]<<" ";
//				}
//				cout<<endl;
//				cout<<t[6].size()<<" "<<t[11].size()<<endl;
//				cout<<endl;
//				cout<<a[i]<<" "<<i<<"th. WA!"<<endl;
//			}
		}
		while(true){
			bool ch = false;
			for(int j = 2;j<=n;j++){
				if(adj[j].front() == adj[1].front()&&adj[j].size()&&adj[1].size()){
					op[p][0] = 2;
					op[p][1] = 1,op[p][2] = j;
					p++;
//					cout<<adj[j].front()<<"and the back of the first deque pop!"<<endl;
					t[adj[1].front()].pop();
					adj[1].pop_front();
					adj[j].pop_front();
					if(adj[j].size() == 0)num[j] = 0;
					else num[j] = t[adj[j].back()].front();
					ch = true;
				}
			}
			if(!ch)break;
		}
	}
}
void solve1(){
	deque<int>t[305];
	for(int i = 1;i<=m;i++){
		int x = a[i]/2+a[i]%2;
		if(t[x].size() == 0){
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].push_back(a[i]);
		}else if(a[i] == t[x].front()){
			op[p][0] = 1;
			op[p][1] = n;
			p++;
			op[p][0] = 2;
			op[p][1] = x;
			op[p][2] = n;
			p++;
			t[x].pop_front();
		}else if(a[i] == t[x].back()){
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].pop_back();
		}else{
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].push_back(a[i]);
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	int K = T%10;
	while(T--){
		p = 0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		if(K == 1){
			solve1();
		}else{
			f(); 
		}
		printf("%d\n",p);
		for(int i = 0;i<p;i++){
			printf("%d ",op[i][0]);
			if(op[i][0] == 1)printf("%d",op[i][1]);
			else printf("%d %d",op[i][1],op[i][2]);
			printf("\n");
		}
	}
	return 0;
}
/*
9:30��T2 
�����ӶȲ�����O(NM)�� 
���������������һ���ģ���ô�����޷����Ӱ�죬ֱ�ӷ���ͬһ��ջ���漴�� 
����м��м��������
���һ���϶��ǰ�һ���Ʒ���һ����ջ��Ȼ�����һ��ջ��ջ���������ǲ�Ȼ��ô��
��ô�м���Ʒŵ���Щջ� 
��֪��
���ȿ�������ջ�����
������ͺܺ����ˣ�Ҫô����ֱ��������Ҫô����һ��ջ��ջ���������������һ����ȷ��Ӧ���ǿ��Ա�֤��
����ջ��
���̣�������һ���뷨��
����ֻ��һ��ջר��װ�������ñ��Ϊ1��ջ�գ����������ջ�����ź͵�һ��ջ��������
Ȼ��֤����ջ����˳���ǵ����ģ������������ǲ�Ȼ�������˺���
���ۿ��У�ʵ����ʼ(10:12)
���ǣ������������checkʲô��
11:14��������������ˣ���
11:43���������� ��û���������� 
12:15:
˼·���ˣ�����
��ɫ������
��ɫֻ���ջ��n+1�֣�����
�ؼ����ڴ��������һ����ɫ������ 
����30~45pts 
*/

