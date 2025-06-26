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
    int k; cin>>k;
    vector<int> v(n);
    for(auto &e:v) cin>>e;
    int total=accumulate(v.begin(),v.end(),0LL);
    sort(v.begin(), v.end());
    v[n - 1]--;
    sort(v.begin(), v.end());
    if (v[n - 1] - v[0] > k || total % 2 == 0){
        cout << "Jerry\n";
        }
    else cout << "Tom\n";

 
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