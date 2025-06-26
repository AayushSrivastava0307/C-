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
 
    int n;cin>>n;
    ///1111=11*101 so only 11 and 111
    // n= a*11+ b*111 --> b== n%11  as b*111==b*(11*10+1)
    // now check n-b*111 greater than 0 or no
    //tf
    int b=n%11;
    if(n%11==0 || n%111 ==0) {
        cout<<"YES"<<endl;
        return;
    }
    (n-b*111)>0?cout<<"YES":cout<<"NO";
    cout<<endl;
 
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