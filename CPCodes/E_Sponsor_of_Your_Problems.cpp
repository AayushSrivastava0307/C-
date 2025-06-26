#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        string L, R;
        cin >> L >> R;
        int n = L.size();
        // dp[pos][tightL][tightR] = minimum cost up to pos
        static int dp[12][2][2];
        for(int i = 0; i <= n; i++)
            for(int t1 = 0; t1 < 2; t1++)
                for(int t2 = 0; t2 < 2; t2++)
                    dp[i][t1][t2] = INF;
        dp[0][1][1] = 0;

        for(int i = 0; i < n; i++){
            for(int tightL = 0; tightL < 2; tightL++){
                for(int tightR = 0; tightR < 2; tightR++){
                    int cur = dp[i][tightL][tightR];
                    if(cur == INF) continue;
                    char lo = tightL ? L[i] : '0';
                    char hi = tightR ? R[i] : '9';
                    for(char c = lo; c <= hi; c++){
                        int add = (c == L[i]) + (c == R[i]);
                        int ntL = tightL && (c == L[i]);
                        int ntR = tightR && (c == R[i]);
                        dp[i+1][ntL][ntR] = min(dp[i+1][ntL][ntR], cur + add);
                    }
                }
            }
        }

        int ans = INF;
        for(int t1 = 0; t1 < 2; t1++)
            for(int t2 = 0; t2 < 2; t2++)
                ans = min(ans, dp[n][t1][t2]);
        cout << ans << "\n";
    }
    return 0;
}