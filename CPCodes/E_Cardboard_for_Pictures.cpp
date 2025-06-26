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
 
    int n; int c;
    cin>>n>>c;
    vector<int> v(n);
    for(auto &e:v) cin>>e;
    int mine=*min_element(v.begin(),v.end());
    sort(v.rbegin(),v.rend());
    int maxlim=(round(sqrt(c))-mine)/2;
    int low=1;
    int high=maxlim;
    while(low<=high){
        int mid=(low)+(high-low)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(v[i]+2*mid)*(v[i]+2*mid);
            if(sum>c) break;
        }
        if(sum==c){
            cout<<mid<<endl;
            return;
        }
        if(sum>c) high=mid-1;
        else low=mid+1;
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