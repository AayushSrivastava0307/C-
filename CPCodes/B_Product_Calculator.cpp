#include <bits/stdc++.h>
using namespace std;
#define int int64_t

//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//

using ull  = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ull> v(n);
    for (auto &e : v) cin >> e;
    i128 limit = 1;
    for (int i = 0; i < k; i++) {
        limit *= 10;
    }
    ull cur = 1;
    for (int i = 0; i < n; i++) {
        i128 prod = (i128)cur * v[i];
        if (prod >= limit) {
            cur = 1;
        } else {
            cur = (ull)prod;
        }
        // dbg(i, cur);
    }

    cout<<cur<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
