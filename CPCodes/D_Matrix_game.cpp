#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
static const int MOD = 1000000007;

vector<int> computeinverses(int n) {
    vector<int> inv(n+1);
    if(n >= 1) inv[1] = 1;
    for(int i = 2; i <= n; i++) {
        inv[i] = MOD - (MOD/i) * inv[MOD % i] % MOD;
    }
    return inv;
}

int bin(int n_mod, int r, const vector<int> &inv) {
    if(r < 0) return 0;
    if(r == 0) return 1;
    int64_t res = 1;
    for(int i = 1; i <= r; ++i) {
        int64_t term = (n_mod - (i - 1)) % MOD;
        if(term < 0) term += MOD;
        res = res * term % MOD;
        res = res * inv[i] % MOD;
    }
    return (int)res;
}

void solve()
{
    int a,b,k;
    cin >>a>>b>>k;
    int64_t n_val = (a -1)*k+1;
    int n_mod = n_val % MOD;
    if(n_mod < 0) n_mod += MOD;
    int n_ans = n_mod;
    vector<int> inv = computeinverses((int)a);
    int64_t C_mod = bin(n_mod, (int)a, inv);
    int64_t term = ((b - 1) % MOD) * (k % MOD) % MOD;
    if(term < 0) term += MOD;
    int m_ans = (term * C_mod + 1) % MOD;
    cout<<n_ans<<" "<<m_ans<<endl;
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