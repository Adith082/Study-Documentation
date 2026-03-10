#include <bits/stdc++.h>

using namespace std;

int dp[1000009];

int solve(int n, int x, int a[]) {

    if(x == 0) return 1;
    else if(x<0) return 0;

    if(dp[x] != -1) return dp[x];

    int res = 0;
    for(int k = 0;k<n;k++) {
        res = ((res % 1000000007) + (solve(n, x - a[k], a) % 1000000007)) % 1000000007;
       // res += solve(n, x - a[k], a);
    }
    return dp[x] = res;
}

int main(){

    int i,j,t,n,x;

    memset(dp, -1, sizeof(dp));

    cin >> n >> x;
    int a[n];
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

   // for(int i = 0;i<n;i++) cout << a[i] << " ";
//    cout << endl;
    int res = solve(n, x, a);

    cout << res << endl;

    return 0;
}
