#include <cstdio>

typedef long long ll;
const int maxn = 1e5 + 8;

class SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls, l, mid
#define Rs mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define lm (mid - l + 1)
#define rm (r - mid)
#define num (r - l + 1)

public:
    int a[maxn], b[maxn], c[maxn];
    
};