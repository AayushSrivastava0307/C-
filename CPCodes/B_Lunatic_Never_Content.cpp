#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve()
{
 
    int n; cin>>n;
    vector<int> v(n);
    for(auto &e:v) cin>>e;
    if(n&1){
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans=__gcd(ans,abs(v[i]-v[n-i-1]));
        }
        cout<<ans<<endl;
        return;
    }
    else{
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans=__gcd(ans,abs(v[i]-v[n-i-1]));



        }
        cout<<ans<<endl;
        return;
    }
 
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