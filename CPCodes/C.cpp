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
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &e:v) cin>>e;
    // difference array
    vector<int> diff(n-1);
    for (int i=0; i<n-1;i++) {
        diff[i]=(v[i+1]>v[i]?1:-1);
    }
    //0== no change ie same 
    //1==peak
    //2==valley
    vector<int> event(n-1, 0);
    for (int k=1;k <n-1;k++) {
        if (diff[k-1]==1&&diff[k]==-1) event[k]=1;
        else if (diff[k-1]==-1&&diff[k]==1) event[k]=2;
        else continue;
    }
    vector<int> next(n,n-1); //the next happenings
    for (int i=n-2;i>=0;i--) { //leave last
        if(event[i]==1 || event[i]==2) next[i]=i;
        else next[i]=next[i+1];
    }

    int ans=0;
    for (int l=0;l<n-1;l++) {
        if (diff[l]!=1) continue; //a1<a2
        int trans1=(l+1<=n-1?next[l+1]:n-1);
        if (trans1>=n-1) continue;
        int trans2=(trans1+1<=n-1?next[trans1+1]:n-1);
        if (trans2>=n-1) continue;
        if (event[trans1]+event[trans2]!=3) continue;
        int trans3=(trans2+1<=n-1?next[trans2+1]:n-1);
        int rlow=trans2;
        if(rlow<l+2) rlow=l+2; //size >=4
        int rhigh=trans3; 
        if (rhigh>rlow) {
            ans += (rhigh-rlow); //add no of subaryrs
            // dbg(l,trans1,trans2,rlow,rhigh,rhigh-rlow);
        }
        else continue;
    }
    cout<<ans<<endl;
}

 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    // cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}