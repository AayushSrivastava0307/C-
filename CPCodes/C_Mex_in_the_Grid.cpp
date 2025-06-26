#include <bits/stdc++.h>
using namespace std;
#define int int64_t

// LC 
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> ans;
    int right = c - 1;
    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int v = 0;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) matrix[top][i] = v++;
        top++;
        for (int i = top; i <= bottom; i++) matrix[i][right] = v++;
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) matrix[bottom][i] = v++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) matrix[i][left] = v++;
            left++;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    spiralOrder(v);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            v[i][j]=n*n-1-v[i][j];
        }
    }
    for (int i=0; i<n;i++) {
        for (int j=0; j<n;j++) {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
