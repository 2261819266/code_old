#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

//Remember freopen!!!!!!!!!!!
//for zjy.

const int MAXN = 250000 + 7;
int a[MAXN], b[MAXN];

signed main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	int t, n, q, l, r;
	cin >> t >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		cin >> b[i];
		
	cin >> q;
	while (q --)
	{
		int ans = 0;
		cin >> l >> r;
		for (int p = l; p <= r; p ++)
			for (int q = p; q <= r; q ++)
			{
				int maxa = 0, maxb = 0;
				for (int i = p; i <= q; i ++)
				{
					maxa = max(maxa, a[i]);
					maxb = max(maxb, b[i]);
				}
				ans += maxa * maxb;
			}
		cout << ans << endl;
	}
	
	
	
	return 0;
}

/*
0 2
2 1
1 2
1
1 2

0 30
9 30 25 18 7 3 29 15 12 16 14 26 24 5 1 8 13 28 6 17 2 22 4 23 27 10 11 19 20 21
27 24 11 26 7 3 8 15 25 10 1 4 18 14 20 23 9 22 29 30 13 28 19 17 2 21 6 12 5 16
30
1 30
1 30
6 30
3 26
4 26
6 28
1 24
4 30
7 29
3 24
7 30
3 26
4 26
2 29
4 30
6 21
8 29
11 14
15 19
19 20
7 30
25 30
7 9
19 30
7 26
13 26
5 30
15 24
18 21
23 29


*/