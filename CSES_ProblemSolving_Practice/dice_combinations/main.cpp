#include <bits/stdc++.h>

using namespace std;

long long int dp[1000004];

long long int solve(long long int n) {



   if(n == 0) return 1;
   else if(n<0) return 0;

       if(dp[n] != -1) {
        return dp[n];
    }

   long long int res = 0;

   for(int i = 1;i<=6;i++) {
       res = ( ( res % 1000000007 ) + (solve(n - i) % 1000000007) ) % 1000000007;
   }

   // return dp[n][val] = temp;
  // cout << "dp[n] " << dp[n] << "     and res  " << res << "  n  " << n << endl;
   return dp[n] = res;

}

int main(){

    long long int i,j,t,n,m;

    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << solve(n) << endl;

   // for(int i = 0;i<=3;i++) cout << dp[i] << " " << endl;

    return 0;
}
