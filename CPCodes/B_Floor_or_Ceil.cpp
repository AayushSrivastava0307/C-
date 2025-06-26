#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
void solve() {
    int x, o1, o2;
    cin >> x >> o1 >> o2;

    int cpyo1 = o1, cpyo2 = o2;
    int cpyx = x;
    if(o1>30){
        o1=30;
        cpyo1=30;
    }
    if(o2>30){
        o2=30;
        cpyo2=30;
    }
    int min = x, max = x;
    while (o2) {
        min = (min + 1) / 2;
        --o2;
    }
    while (o1) {
        min = min / 2;
        --o1;
    }
    while (cpyo1) {
        cpyx = cpyx / 2;
        max = cpyx;
        --cpyo1;
    }
    while (cpyo2) {
        cpyx = (cpyx + 1) / 2;
        max = cpyx;
        --cpyo2;
    }
    cout << min << " " << max << endl;
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