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
    int n,m;
    cin>>n>>m;
    char v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int row1=0;
    int rowc=0;
    for(int i=0;i<n;i++){
        row1=0;
        for(int j=0;j<m;j++){
            if(v[i][j]-'0'==1) row1++;
        }
        if(row1&1) rowc++;
    }
    int col1=0;
    int colc=0;
    for(int i=0;i<m;i++){
        col1=0;
        for(int j=0;j<n;j++){
            if(v[j][i]-'0'==1) col1++;
        }
        if(col1&1) colc++;
    }
    cout<<max(rowc,colc)<<endl;
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