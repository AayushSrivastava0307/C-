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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int globalmax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            globalmax=max(globalmax,v[i][j]);
        }
    }
    int secondmax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!=globalmax) secondmax=max(secondmax,v[i][j]);
        }
    }
    int totalgmax=0;
    vector<int> rowcnt(n), colcnt(m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j] == globalmax) {
                totalgmax++;
                rowcnt[i]++;
                colcnt[j]++;
            }
        }
    }
    vector<int> rowmax(n), colmax(m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            rowmax[i] = max(rowmax[i], v[i][j]);
        }
    }
    for(int j=0;j<m;j++) {
        for(int i = 0; i < n; i++) {
            colmax[j] = max(colmax[j], v[i][j]);
        }
    }
    int ans =globalmax;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int rem =rowcnt[i]+colcnt[j]-(v[i][j]==globalmax);
            int remain =totalgmax-rem;
            int try1 =(remain>0?globalmax:secondmax);
            int try2 =max(rowmax[i],colmax[j]) - 1;
            ans =min(ans,max(try1,try2));
        }
    }
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