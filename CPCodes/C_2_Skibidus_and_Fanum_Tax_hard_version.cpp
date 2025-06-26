#include<bits/stdc++.h>
using namespace std;
#define int int64_t

//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//


bool check(vector<int> &a, vector<int> &b, int idx) {
    int low = 0, high = b.size() - 1;
    int candidate = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(b[mid] - a[idx] >= a[idx-1]){
            candidate = mid;
            high = mid - 1; 
        }
        else {
            low = mid + 1;
        }
    }
    if(candidate == -1) {
        return(a[idx]>=a[idx-1]);
    }
    if(a[idx] >= a[idx-1])
         a[idx] = min(a[idx], b[candidate] - a[idx]);
    else 
         a[idx] = b[candidate] - a[idx]; // as a[idx] can be verrry min wow!
    return (a[idx] >= a[idx-1]);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    if(is_sorted(a.begin(),a.end())){
        cout<<"YES"<<endl;
        return;
    }
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    
    for(int i = 1; i < n; i++){
        if(!check(a, b, i)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
