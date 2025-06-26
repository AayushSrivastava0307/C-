#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int ans = 0;
    for (int k = 2; k < n; k++) {
        int x;
        if (k == n - 1 || a[k] == a[n - 1]) {
            x = a[k];
        } else {
            x = max(a[k], a[n - 1] - a[k]);
        }
 
        int i = 0, j = k - 1;
        int more = 0;
        while (i < j) {
            if (a[i] + a[j] > x) {
                more += (j - i);
                j--;
            } else {
                i++;
            }
        }
        ans += more;
    }
    cout << ans << endl;
}
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}