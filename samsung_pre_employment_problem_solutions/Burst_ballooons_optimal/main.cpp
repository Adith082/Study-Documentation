#include <bits/stdc++.h>

using namespace std;

long long int dp[30][30];

long long int solve(long long int l, long long int r, long long int a[], long long int n) {

    long long int res = 0;

    if(dp[l][r] != -1) return dp[l][r];
    for(int i = l; i<=r; i++) {

        long long int temp = 0;

        if(((l - 1) == 0) && ((r + 1) == ( n + 1 ))) {
            temp = a[i];
        }   else {
            temp = (a[l-1] * a[r + 1]);
        }
        temp += solve(l, i-1, a, n) + solve(i+1, r, a, n);
        res = max(res, temp);
    }

    return dp[l][r] = res;
}

int main(){

    long long int i,j,t,n;
    cin >> n;
    long long int a[n + 2];
    memset(dp, -1, sizeof(dp));
    a[0] = 1;
    a[n + 1] = 1;
    for(int i = 1; i<=n; i++) cin >> a[i];
    cout << solve(1, n, a, n) << endl;
    return 0;
}
