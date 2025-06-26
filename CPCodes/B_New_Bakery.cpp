#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int profit(int n, int a, int b, int k) {
    return k*(b+1) - (k*(k+1)/2) + a*(n-k);
}

void solve() {
    int n, a, b;
    cin>>n>>a>>b;
    int l = 0, r = min(n, b), ans = 0;
    //ternary search 
    while (l <= r) {
        int mid1 = l+(r-l) / 3;   //3 equal parts
        int mid2 = r-(r-l) / 3;
        int profit1 = profit(n,a,b, mid1);
        int profit2 = profit(n,a,b, mid2);
        ans = max(ans, max(profit1, profit2));
        if (profit1 < profit2)
            l = mid1 + 1;  
        else
            r = mid2 - 1; 
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
