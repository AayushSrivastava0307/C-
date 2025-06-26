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
    int w, h, a, b;
    cin>>w>>h>>a>>b;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    // (x,y) E(i*a,b*j) i j are intgs
    //w,h dont matter
    // cant int rem1=x1%a; //-ve handl
    int remx1=(x1%a+a)%a;
    int remx2=(x2%a+a)%a;
    int remy1=(y1%b+b)%b;
    int remy2=(y2%b+b)%b;
    bool check1=false;
    if(remx1==remx2){// same offset and either overlap or shifted 
        if(remy1==remy2 || x1!=x2) check1=true;
    }
    bool check2=false;
    if(remy1==remy2){
        if(remx1==remx2 || y1!=y2) check2=true;
    }
    if(check1 || check2){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;

 
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