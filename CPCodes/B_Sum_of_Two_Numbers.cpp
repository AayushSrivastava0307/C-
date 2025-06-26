#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        bool give = false;
        string x="", y="";
        for(char c: s){
            int d = c - '0';
            if(d % 2 == 0){
                x += char('0' + d/2);
                y += char('0' + d/2);
            } else {
                int a = d/2 + (give ? 1 : 0);
                int b = d - a;
                x += char('0' + a);
                y += char('0' + b);
                give = !give;
            }
        }


        auto strip = [&](string &t){
            int i = 0, n = t.size();
            while(i+1 < n && t[i]=='0') i++;
            if(i>0) t.erase(0, i);
        };
        strip(x);
        strip(y);

        cout << x << " " << y << "\n";
    }
    return 0;
}
