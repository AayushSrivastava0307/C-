#include <bits/stdc++.h>
using namespace std;
#define int int64_t

//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//

void solve(){
    int n, k;
    cin >> n >> k;
    int q = (n + k - 1) / k; 
    int L = q * k;
    int low = 1, high = k;  
    int ans = high;
    while(low <= high){
        int mid = (low + high) / 2;
        if(n * mid >= L){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout<<ans<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    cin >> tc;
    
    while(tc--){
        solve();
    }
    return 0;
}