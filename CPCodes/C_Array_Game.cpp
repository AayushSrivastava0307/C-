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
 
    int n;
    int k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &e:v) cin>>e;
    if(k>=3) {
        cout<<0<<endl;
        return;
    }
    if(k==1){   
        sort(v.begin(),v.end());
        int mine=v[0];
        int mindiff=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            mindiff=min(mindiff,v[i+1]-v[i]);
        }
        cout<<min(mine,mindiff)<<endl;
        return;
    }
    // k==2 case
    if(k==2){
    sort(v.begin(),v.end());
    int ans=LLONG_MAX;
    for(int i=0;i<n-1;i++){
        ans=min(ans,v[i+1]-v[i]); //case of one op
    }
    for (int i = 0; i < n; i++){ // case of two ops
        for (int j = i + 1; j < n; j++){
            int d = abs(v[i] - v[j]);
            int ind = lower_bound(v.begin(), v.end(), d) - v.begin();
            if (ind <= n-1){
                ans = min(ans, abs(v[ind] - d));
            }
            if (ind >= 1){
                ans = min(ans, abs(v[ind - 1] - d));
            }
        }
    }

    cout<<min(ans,v[0])<<endl; //case of no op
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