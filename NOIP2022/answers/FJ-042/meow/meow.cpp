#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	int id=T%10;
	while(T--){
		int n=read(),m=read(),k=read();
	}
	return 0;
}