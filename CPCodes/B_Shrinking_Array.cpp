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
    if(n==2){
        if(abs(v[0]-v[1])<=1){cout<<0<<endl;return;}
        cout<<-1<<endl; return;
    }
    for(int i=1;i<n;i++){
        if(abs(v[i]-v[i-1])<=1) {cout<<0<<endl; return;}
    }
    bool sorted1=true;
    for(int i=1;i<n;i++){
        if(v[i]>v[i-1]) continue;
        else {sorted1=false; break;}
    }
    if(!sorted1){
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1]) continue;
            else{
                cout<<1<<endl; return;
            }
        }
        cout<<-1<<endl; return;
    }
    else {cout<<-1<<endl;return;}
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