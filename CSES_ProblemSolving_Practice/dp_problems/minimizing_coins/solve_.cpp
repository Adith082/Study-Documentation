#include <bits/stdc++.h>

using namespace std;

int dp[1000009];

int solve(int n, int x, int a[]) {

    if(dp[x] != -1) return dp[x];

    if(x < 0) return 100000000;
    else if(x==0) return 0;

    int way = 0;
    int minn = 100000000;
    for(int k = 0;k<n;k++) {
        if(x>=a[k])  minn = min(minn, solve(n, x - a[k], a) + 1);
    }
    return dp[x] = minn;
}

int main(){

    int i,j,t,n,x;
    memset(dp, -1, sizeof(dp));
    cin >> n >> x;
    int a[n];

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    int res = solve(n, x, a);
    if(res >= 100000000) {
        cout << -1 << endl;
    }   else {
        cout << res << endl;
    }
    return 0;
}
