#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
typedef pair<int,int> ppi;
void solve()
{
 
    int n;cin>>n;
    vector<int> a(n);
    for(auto &e:a) cin>>e;
    vector<int> b(n);
    for(auto &e:b) cin>>e;
    vector<ppi> ans;
    int cnter=n;
    while(cnter--){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                ans.push_back({1,i+1});
            }
        }
    }
    cnter=n;
    while(cnter--){
        for(int i=0;i<n-1;i++){
            if(b[i]>b[i+1]){
                swap(b[i],b[i+1]);
                ans.push_back({2,i+1});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            swap(a[i],b[i]);
            ans.push_back({3,i+1});
        }
        
    }
    cout<<ans.size()<<endl;
    for(auto &[no,idx]:ans){
        cout<<no<<" "<<idx<<endl;
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