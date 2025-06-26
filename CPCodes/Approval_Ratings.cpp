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
 
    vector<int> v(5);
    for(auto &e:v) cin>>e;
    int scorebefore=(accumulate(v.begin(),v.end(),0LL));
    if(scorebefore>=35) cout<<0<<endl;
    else{
        sort(v.begin(),v.end());
        int ans=0;
        int i=0;
        while(scorebefore<35){
            int diff=10-v[i];
            scorebefore+=diff;
            ans+=100;
            i++;
        }
        cout<<ans<<endl;
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