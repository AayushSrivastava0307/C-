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
    vector<int> v(n);
    for(auto &e:v) cin>>e; 
    if(n==1){
        cout<<v[0]<<endl;
        return;
    }
    if(n==2){
        cout<<v[0]+v[1]<<endl; return;
    }
    if(k==1 && n>=3){
        int first=v[0];
        int last=v[n-1];
        int maxe=v[1];
        for(int i=1;i<n-1;i++){
            maxe=max(maxe,v[i]);
        }
        int realmax=max({maxe+first,maxe+last,last+first});
        cout<<realmax<<endl;
        return;
    }
    multiset<int> st;
    for(int i=0;i<n;i++){
        st.insert(v[i]);
    }
    int maxx=0;
    while((k)-- && !st.empty()){
        auto it=--st.end();
        maxx+=*it;
        st.erase(it);
    }
    auto last=--st.end();
    maxx+=*last;
    cout<<maxx<<endl;
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