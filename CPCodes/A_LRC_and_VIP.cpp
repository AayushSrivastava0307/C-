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
    int maxe=*max_element(v.begin(),v.end());
    bool flag=true;
    for(int i=1;i<n;i++){
        if(v[i-1]!=v[i]){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(auto e:v){
            if(e==maxe) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
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