#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve()
{
 
    int n; cin>>n;
    string s; cin>>s;
    vector<int> suff(26, 0), pref(26, 0);
    for (int i=1;i<n;i++){
        suff[s[i]-'a']++;
    }
    pref[s[0]-'a']=1;
    bool flag=false;
    for (int i=1; i<n-1 && !flag; i++) {
        int c = s[i]-'a';
        suff[c]--;
        if (pref[c]>0 || suff[c]>0) {
            flag=true;
            break;
        }
        pref[c]++;
    }
    string ans=(flag)?"Yes":"No";
    cout<<ans<<endl;
 
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