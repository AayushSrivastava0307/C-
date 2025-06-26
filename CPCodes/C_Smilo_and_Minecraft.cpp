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
 
    int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        int tot=0; //total gold
        for (auto& row : grid) {
            cin >> row;
            for(char c:row){
                if(c=='g'){
                    tot+=1;
                }
            }
        }
        vector<vector<int>> PS(n + 1, vector<int>(m + 1, 0)); //padding added
        for (int row = 1; row < n+1; ++row) {
            for (int col = 1; col < m+1; ++col) {
                int gold = (grid[row-1][col-1] == 'g');
                PS[row][col] =
                    PS[row][col-1] + PS[row-1][col]
                    - PS[row-1][col-1] + gold;
            }
        }
        auto querygold=[&](vector<vector<int>> &PS,int tr,int lc,int br,int rc){
            return PS[br+1][rc+1]- PS[tr][rc+1]- PS[br+1][lc]+PS[tr][lc];
        };
        int minloss=tot;
        int radius=k-1; //all destroy in this

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '.') {
                    int tr = max(0LL, row -radius); //clamper
                    int lc = max(0LL, col - radius);
                    int br = min(n - 1, row + radius);
                    int rc = min(m - 1, col + radius);

                    int lostgold = querygold(PS, tr, lc, br, rc);
                    minloss = min(minloss, lostgold);
                }
            }
        }

        int ans=tot-minloss; //we only have to minimise the first explosion losss as all can be collected by 1,1 shift
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