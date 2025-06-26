#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 const int MOD=998244353;

void solve()
{
 
    int n; cin>>n;
    vector<int> a(n);
    for(auto &e:a) cin>>e;
    sort(a.begin(),a.end());
    int ans=1;
    for(int i=0;i<n;i++){
        int tryit=a[i]-i;
        if(tryit<=0){
            cout<<0<<endl;
            return;
        }
        else ans=(ans%MOD*(tryit%MOD))%MOD;
    }
    cout<<ans<<endl;
 
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