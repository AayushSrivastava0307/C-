#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve() {
    int k, a, b, x, y;
    cin>>k>>a>>b>>x>>y;
    auto grill = [](int k, int req1, int req2, int dec1, int dec2) {
        int cnt1=0;
        if (k >=req1) {
            cnt1 =(k-req1)/dec1+1;
            k -=cnt1*dec1;
        }
        int cnt2=0;
        if (k >=req2) {
            cnt2 = (k-req2)/dec2+1;
        }
        return cnt1 + cnt2;
    };

    int try1 = grill(k,a,b,x,y);
    int try2 = grill(k,b,a,y,x);
    cout<<max(try1, try2)<<endl;
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