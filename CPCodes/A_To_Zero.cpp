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
 
    int n,k;
    cin>>n>>k;
    int ans=0;
    if(n&1){
        ans+=1;
        ans+=((n-k)%(k-1))==0? (n-k)/(k-1) : ((n-k)/(k-1))+1;
        cout<<ans<<endl;
        return;
    }
    else{
        ans+=  (n%(k-1))==0 ? (n/(k-1)) :(n/(k-1))+1;
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