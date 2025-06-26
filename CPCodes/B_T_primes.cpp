#include <bits/stdc++.h>
using namespace std;
#define int int64_t

//--------------------------------------------------Debugger-----------------------------------------------------//
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//

const int sievetill = 1e6; //as 1e12th roots
vector<bool> prime(sievetill + 1, true);
//remember to call sieve in main
void sieve() {
    prime[0] = prime[1] = false;  
    for (int p = 2; p * p <= sievetill; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= sievetill; i += p)
                prime[i] = false;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (num == 1) {
            cout << "NO" << endl;
            continue;
        }
        int x = (int)sqrt(num);
        if (x * x == num && prime[x])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    sieve();
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
