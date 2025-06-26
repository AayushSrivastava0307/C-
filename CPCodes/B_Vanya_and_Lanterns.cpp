#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
#define double long double 

 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
bool check(vector<int> &lamps,double lit,int l){
    int n=lamps.size();
    if ((double)lamps[0] - lit > 0) return false;
    if ((double)lamps[n - 1] + lit < l) return false;
    for(int i=0;i<n-1;i++){
        if(   (double)lamps[i]+lit   <  (double)lamps[i+1]-lit){
            return false;
        }
    }
    return true;
}
 
void solve()
{
 
    int n,l;
    cin>>n>>l;
    vector<int> lamps(n);
    for(auto &e:lamps) cin>>e;
    sort(lamps.begin(),lamps.end());
    double low=0;
    double high=l;
    double ans=0;
    bool edgecheck1=true;
    for(int i=0;i<n;i++){
        if(lamps[i]==l){
            continue;
        }
        else edgecheck1=false;
    }
    bool edgecheck2=true;
    for(int i=0;i<n;i++){
        if(lamps[i]==0){
            continue;
        }
        else edgecheck2=false;
    }
    if(edgecheck1 || edgecheck2){
        cout<<fixed<<setprecision(10)<<l/1.0<<endl;
        return;
    }
    while(high-low>1e-10){
        double mid=(low+high)/2.0;
        if( check(lamps,mid,l)){
            ans=mid;
            high=mid;
        } 
        else low=mid;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
 
}
 
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    // cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}