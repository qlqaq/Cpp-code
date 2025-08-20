//P8856 [POI 2002] 火车线路
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//const int MAXN=;
//int maxn=INT_MIN;
//int minn=INT_MAX;
int n,m,q;
struct segTree{
    int val;
}segTree[240005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    while(q--) {
        int x,y,z;
        cin >> x >> y >> z;
        bool f=find();
        cout << f?'T':'N' << endl;
        if(f) update();
    }
    return 0;
}