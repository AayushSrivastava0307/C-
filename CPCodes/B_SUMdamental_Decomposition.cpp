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
 
    int n,x;
    cin>>n>>x;
    if(n==1 &&x==0){
        cout<<-1<<endl;
        return;
    }
    if(x==0){
        if(n&1){
            cout<<n+3<<endl; //2,3 in array usage intead of 1,1
        }
        else cout<<n<<endl; //alwasy possible 1,1,,1,1
    }
    else if(x==1){
        if(n&1) cout<<n<<endl; //1,1,1,1,1
        else cout<<n+3<<endl; //2,3 instead of 1,1
    }
    else{
        int bits = __builtin_popcountll(x);
        if(bits>=n) cout<<x<<endl; //x is the min as contxor<=sigma
        else{
            if((n-bits)&1) cout<<x+n-bits+1<<endl;
            else cout<<x+n-bits<<endl;
        }
    }
 
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