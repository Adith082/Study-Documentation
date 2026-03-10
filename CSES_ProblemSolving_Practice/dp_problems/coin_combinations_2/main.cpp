#include <bits/stdc++.h>

using namespace std;

int dp[200][1000007];

int solve(int i, int n, int x, int a[]) {

    if(x == 0) return 1;
    else {
        if(x<0 || (i == (n))) return 0;
    }

    if(dp[i][x] != -1) return dp[i][x];

    int res = 0;
    if(x>=a[i]) {
        res = ((res % 1000000007) + (solve(i, n, x - a[i], a) % 1000000007)) % 1000000007;
    }   res = ((res % 1000000007) + (solve(i + 1, n, x, a) % 1000000007)) % 1000000007;

       // res += solve(n, x - a[k], a);
    return dp[i][x] = res;
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
    int res = solve(0, n, x, a);

    cout << res << endl;

    return 0;
}
