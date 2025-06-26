#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    //hashing using set
    vector<int> pre(n, 0), suff(n, 0);
    unordered_set<char> prehash;
    for (int i = 0; i < n; i++) {
        prehash.insert(s[i]);
        pre[i] = prehash.size();
    }
    unordered_set<char> suffhash;
    for (int i = n - 1; i >= 0; i--) {
        suffhash.insert(s[i]);
        suff[i] = suffhash.size();
    }

    int maxD = 0;
    for (int i = 0; i < n - 1; i++) {
        maxD = max(maxD, pre[i] + suff[i + 1]);
    }

    cout << maxD << endl;
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