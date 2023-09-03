/*˼·
��¼ÿ����˫�ĵ��� k1,k2...kn
�� xi=2^ki-1
��Ϊ ��{i=1...n} ����ѡ i �� x ֮��*2^(m-����·����) �����ǲ����󰡰�����
*/


// ��ݴ���ʱ�临�ӶȲ��Բ���д�����ˣ�ֻ�б�˫���������� 2 ʱ��ȷ���� 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

template<class T>
struct Solution {
	static constexpr int N=5e5+10,M=3e6+10;
	Solution():hd(N),to(M),nx(M),dfn(N),low(N) {}

	std::vector<int>hd,to,nx;
	int etot=2;  // ���ڱ�Ǹ��
	void addEdge(int u,int v) {
		nx[etot]=hd[u];
		to[etot]=v;
		hd[u]=etot;
		etot++;
	}

	std::vector<int>dfn,low;
	std::bitset<M>evis; // �����߷���ߣ�����Ҫ���
	std::bitset<M>cut; // ��߱��
	int tartot=0;
	void tarjan(int u) {
		dfn[u]=low[u]=++tartot;
		for(int e=hd[u],v=to[e]; e; v=to[e=nx[e]])
			if(!evis[e]) {
				evis[e^1]=1; // ����߱�ǣ�����ͼ Tarjan ���鷳��
				if(dfn[v])
					low[u]=std::min(low[u],dfn[v]);
				else {
					tarjan(v);
					low[u]=std::min(low[u],low[v]);
					if(low[v]>dfn[u])  // ���Ǹ�㣡�Ǹ�ߣ������� >=������
						cut[e]=cut[e^1]=1;
				}
			}
	}

	std::bitset<N>pvis; // dfs ��ͨ��� vis ���
	std::vector<T>bs;  // 2^��˫�ĵ���-1
	int dfs(int u) {
		pvis[u]=1;
		int res=1;
		for(int e=hd[u],v=to[e]; e; v=to[e=nx[e]])
			if(!cut[e]&&!pvis[v]) // ��߲�����
				res+=dfs(v);
		return res;
	}

	// ����������߶������ɴ�� build ����
	std::vector<T> build(int l,int r) { // ����ҿ�
		std::vector<T> res(r-l+1);
		res[0]=1;
		if(r-l==1)
			res[1]=bs[l];
		else {
			int mid=l+r>>1;
			auto v1=build(l,mid),v2=build(mid,r);
			for(int i=1; i<=r-l; i++) //������ô�Ż���������
				for(int j=std::max(0,i-(r-mid)); j<=mid-l; j++)
					res[i]+=v1[j]*v2[i-j];
		}
		return res;
	}

	void solve() {
		int n,m;
		std::cin>>n>>m;

		for(int i=1; i<=m; i++) {
			int u,v;
			std::cin>>u>>v;
			addEdge(u,v),addEdge(v,u);
		}
		tarjan(1);  // ��Ŀ��֤ͼ��ͨ�����ģ�
		for(int i=1; i<=n; i++)
			if(!pvis[i]) // ��������ͨ�飨��˫��
				bs.push_back(T(2).pow(dfs(i))-T(1));
		auto v=build(0,bs.size());
		T ans;
		for(int i=1; i<=bs.size(); i++)
			ans+=v[i]*T(2).pow(m-i+1);
		std::cout<<ans.v;
	}
};

struct ModInt {
	static constexpr int mod=1e9+7;
	long long v;

	ModInt():v(0) {}
	ModInt(const int &x):v((x%mod+mod)%mod) {}
	ModInt(const long long &x):v((x%mod+mod)%mod) {}
	ModInt(const ModInt &x):v(x.v) {}

	friend ModInt operator+(const ModInt &a,const ModInt &b) {
		return ModInt(a.v+b.v);
	}
	friend ModInt operator-(const ModInt &a,const ModInt &b) {
		return ModInt(a.v-b.v);
	}
	friend ModInt operator*(const ModInt &a,const ModInt &b) {
		return ModInt(a.v*b.v);
	}

	void operator=(const int &x) {
		v=(x%mod+mod)%mod;
	}
	void operator+=(const ModInt &x) {
		v=(v+x.v)%mod;
	}
	void operator*=(const ModInt &x) {
		v=(v*x.v)%mod;
	}

	ModInt pow(int b) {
		ModInt res(1);
		for(ModInt tmp(v); b; tmp*=tmp,b>>=1)
			if(b&1)
				res*=tmp;
		return res;
	}
};

#define FileIO_qwq(name) \
	freopen(#name".in","r",stdin),\
	freopen(#name".out","w",stdout);

int main() {
	FileIO_qwq(barrack);

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	Solution<ModInt> sol;
	sol.solve();

	return 0;
}
