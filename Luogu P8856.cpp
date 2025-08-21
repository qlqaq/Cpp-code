//P8856 [POI 2002] 火车线路
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 60005;
int n, lim, q, dat[N << 2], tg[N << 2];
inline void pushup(int p){dat[p] = max(dat[p << 1], dat[p << 1 | 1]);}
inline void pushdown(int p, int l, int r){
	if (tg[p]){
		dat[p << 1] += tg[p]; dat[p << 1 | 1] += tg[p];
		tg[p << 1] += tg[p]; tg[p << 1 | 1] += tg[p];
		tg[p] = 0;
	}
}
void update(int p, int l, int r, int lpos, int rpos, int k){
	if (l > rpos || r < lpos) return;
	if (lpos <= l && r <= rpos){
		dat[p] += k;
		tg[p] += k;
		return;
	} 
	pushdown(p, l, r);
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, lpos, rpos, k); update(p << 1 | 1, mid + 1, r, lpos, rpos, k);
	pushup(p); 
} 
int query(int p, int l, int r, int lpos, int rpos){
	if (l > rpos || r < lpos) return -2e9;
	if (lpos <= l && r <= rpos) return dat[p];
	pushdown(p, l, r);
	int mid = (l + r) >> 1;
	return max(query(p << 1, l, mid, lpos, rpos), query(p << 1 | 1, mid + 1, r, lpos, rpos)); 
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	scanf("%d%d%d", &n, &lim, &q);
	while (q--){
        int l,r,x;
		scanf("%d%d%d", &l, &r, &x);
		update(1, 1, n, l, r - 1, x);
		if (query(1, 1, n, l, r - 1) > lim){
			update(1, 1, n, l, r - 1, -x);
			printf("N\n");
		}
		else printf("T\n");
	}
    return 0;
}