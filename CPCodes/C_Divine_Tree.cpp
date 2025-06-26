#include <bits/stdc++.h>
using namespace std;
#define int int64_t

//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//

void solve()
{
    int n, m;
    cin >> n >> m;
    bool found = false;
    int chosenk = -1;
    int sumK = 0;
    for(int k = 1; k <= n; k++){
        if(k > 1) sumK += (k - 1);
        int mmin = k + n - 1;
        if(m < mmin) break;
        int m_max = k*n-sumK;
        if(m <= m_max){
            chosenk = k;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "-1"<<endl;
        return;
    }
    int k = chosenk;
    int sumK2 = k * (k - 1) / 2;
    int curSum = n + sumK2;
    int D = m - curSum;
    int E = n - k;
    vector<int> extras(k + 1, 0);
    for(int x = k; x >= 2 && D > 0 && E > 0; x--){
        int gain = x - 1;
        int canTake = D / gain;
        if(canTake <= 0) continue;
        int t = min<int>(E, canTake);
        extras[x] = t;
        E -= t;
        D -= gain * t;
    }
    if(D){
        cout << "-1"<<endl;
        return;
    }
    extras[1] = E;
    vector<int> avail;
    avail.reserve(n - k);
    for(int v = k + 1; v <= n; v++){
        avail.push_back(v);
    }
    int ptr = 0;
    vector<pair<int,int>> edges;
    edges.reserve(n - 1);
    for(int x = 1; x < k; x++){
        edges.push_back({k, x});
        for(int i = 0; i < extras[x]; i++){
            int y = avail[ptr++];
            edges.push_back({x, y});
        }
    }
    for(int i = 0; i < extras[k]; i++){
        int y = avail[ptr++];
        edges.push_back({k, y});
    }
    cout<<k<<endl;
    for(auto &e : edges){
        cout << e.first <<" "<< e.second <<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
