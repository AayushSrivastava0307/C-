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
    vector<pair<int,int>> vpp(n);
    for(int i=0;i<n;i++){
        cin>>vpp[i].first>>vpp[i].second;
    }
    int mincost=INT_MAX;
    bool found=false;
    for(int i=0;i<n;i++){
        if(vpp[i].first>=7){
            found=true;
            mincost=min(mincost,vpp[i].second);
        }
    }
    if(!found) cout<<-1<<endl;
    else{
        cout<<mincost<<endl;
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