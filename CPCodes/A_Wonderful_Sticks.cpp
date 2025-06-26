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
    string s; cin>>s;
    vector<int> ans;
    int l=1;
    int r=n;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='<'){
            ans.push_back(l++);
        }
        else ans.push_back(r--);
    }
    ans.push_back((l<=n?l:r));
    reverse(ans.begin(),ans.end());
    for(auto e:ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return;

 
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