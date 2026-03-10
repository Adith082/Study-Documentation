
/*
#include <bits/stdc++.h>

using namespace std;


int main(){

    int i,j,t,n,x;
    cin >> n >> x;
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    int a[n];
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    for(int i = 0;i<n;i++) dp[i][0] = 1;
    for(int j = 0;j<=x;j++) {
        if((j - a[0]) == 0) dp[0][j] = 1;
        else dp[0][j] = 0;
    }
    for(int i = 0;i<n;i++) {

        for(int j = 1;j<=x;j++) {
           if(j>=a[i]) dp[i][j] = ((dp[i][j])  + (dp[i][j - a[i]])) % 1000000007;
           if((i - 1)>=0) dp[i][j] = ((dp[i][j] + (dp[i - 1][j]))) % 1000000007;
        }
    }

    cout << dp[n-1][x] << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    // Coin loop outside (important!)
    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    cout << dp[x] << endl;
}



