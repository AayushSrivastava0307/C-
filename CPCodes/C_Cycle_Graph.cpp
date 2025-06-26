#include<bits/stdc++.h>
using namespace std;
#define int int64_t
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//


//gfg
bool isCycleUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            if (isCycleUtil(i, adj, visited, v)) return true;
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isConnected(int N, vector<vector<int>> &adj) {
    vector<bool> visited(N + 1, false);
    isCycleUtil(1, adj, visited, -1);
    for (int i = 1; i <= N; i++) if (!visited[i]) return false;
    return true;
}

void solve() {
    int N, M;
    cin >> N >> M;
    if (M != N) {cout << "No" << endl; return;}
    vector<vector<int>> adj(N + 1);
    vector<int> degree(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= N; i++) if (degree[i] != 2) {cout << "No" << endl; return;}
    if (isConnected(N, adj)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
