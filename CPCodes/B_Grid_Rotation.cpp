#include<bits/stdc++.h>
using namespace std ;
#define int int64_t

//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//

void rotate(vector<vector<char> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> S(n, vector<char>(n));
    vector<vector<char>> T(n, vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> S[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> T[i][j]; 
        }
    }

    // copy original S for rotation
    vector<vector<char>> cpyS(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cpyS[i][j] = S[i][j];
        }
    }

    vector<vector<char>> S90(n, vector<char>(n));
    vector<vector<char>> S180(n, vector<char>(n));
    vector<vector<char>> S270(n, vector<char>(n));
    
    rotate(cpyS);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            S90[i][j] = cpyS[i][j];
        }
    }
    rotate(cpyS);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            S180[i][j] = cpyS[i][j];
        }
    }
    rotate(cpyS);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            S270[i][j] = cpyS[i][j];
        }
    }


    int cnt0 = 0, cnt1 = 1, cnt2 = 2, cnt3 = 3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(S[i][j] != T[i][j]) cnt0++;
            if(S90[i][j] != T[i][j]) cnt1++;
            if(S180[i][j] != T[i][j]) cnt2++;
            if(S270[i][j] != T[i][j]) cnt3++;
        }
    }

    cout << min({cnt0, cnt1, cnt2, cnt3}) << '\n';
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
