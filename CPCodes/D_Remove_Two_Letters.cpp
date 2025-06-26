#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
// bool pal(string & s){
//     return s == string(s.rbegin(), s.rend()) ? true : false;
// }
 
void solve()
{
 
    int n;
    cin>>n;
    string s; cin>>s;
    //alt check;
    int alt=0;
    for(int i=0;i<s.size()-2;i++){
        if(s[i]==s[i+2]){
            alt+=1;
        }
    }
    cout<<s.size()-alt-1<<endl;


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