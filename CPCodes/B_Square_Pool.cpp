#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve() {
    int n,s;
    cin >>n>>s;
    int cnt=0;
    while (n--) {
        int dx,dy,x,y;
        cin >>dx>>dy>>x>>y;
        // we need dx*x E dy*y (mod s)
        int a = (dx * x) % s; 
        if (a < 0) a += s;
        int b = (dy * y) % s; 
        if (b < 0) b += s;
        if (a == b) cnt++;
    }
    cout<<cnt<<endl;
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