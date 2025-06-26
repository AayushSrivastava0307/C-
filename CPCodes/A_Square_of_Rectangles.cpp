#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve() {
    vector<int> l(3), b(3);
    for (int i =0;i<3;i++) {
        cin>>l[i]>>b[i];
    }
    int area = l[0]*b[0] + l[1]*b[1] + l[2]*b[2];
    int S = llround(sqrt((long double)area));
    if (S*S != area) {
        cout<<"NO"<<endl;
        return;
    }
    bool ok = false;
    if (l[0]==S && l[1]==S && l[2]==S && b[0]+b[1]+b[2]==S)
        ok = true;
    if (b[0]==S && b[1]==S && b[2]==S && l[0]+l[1]+l[2]==S)
        ok = true;
    for (int i = 0; i < 3; i++) {
        if (l[i] != S) continue;
        int remH = S - b[i];
        int j = (i+1)%3, k = (i+2)%3;
        if (remH>0 &&b[j]==remH && b[k]==remH && l[j]+l[k]==S) ok = true;
    }
    for (int i = 0; i < 3; i++) {
        if (b[i] != S) continue;
        int remW = S-l[i];
        int j=(i+1)%3, k =(i+2)%3;
        if (remW>0 && l[j]==remW && l[k]==remW && b[j]+b[k]==S) ok = true;
    }
    string ans=ok?"YES":"NO";
    cout<<ans<<endl;
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