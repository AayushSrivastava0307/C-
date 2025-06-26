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
    int H,W,N;
    cin>>H>>W>>N;

    vector<vector<int>> rows(H+1), cols(W+1);
    vector<int> rowcnt(H+1,0), colcnt(W+1,0);
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        rows[x].push_back(y);
        cols[y].push_back(x);
        rowcnt[x]++;
        colcnt[y]++;
    }

    vector<char> rowrem(H+1,0), colrem(W+1,0);
    int Q;
    cin>>Q;
    while(Q--){
        int t,v;
        cin>>t>>v;
        if(t==1){
            if(rowrem[v]){
                cout<<0<<endl;
            } else {
                int ans=rowcnt[v];
                cout<<ans<<endl;
                rowrem[v]=1;
                for(int y: rows[v]){
                    if(!colrem[y]){
                        colcnt[y]--;
                    }
                }
            }
        } else {
            if(colrem[v]){
                cout<<0<<endl;
            } else {
                int ans=colcnt[v];
                cout<<ans<<endl;
                colrem[v]=1;
                for(int x: cols[v]){
                    if(!rowrem[x]){
                        rowcnt[x]--;
                    }
                }
            }
        }
    }
}

 
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    // cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}