#include <bits/stdc++.h>

using namespace std;

int dp[200005][20];
vector <int> adj[200005];

void bin_lift(int src, int par) {

   // cout << "paths " << src << endl;

        dp[src][0] = par;
        for(int i = 1;i<20;i++) {
            if(dp[src][i-1] != -1)
              dp[src][i] = dp[dp[src][i - 1]][i - 1];
            else dp[src][i] = -1;
        }


    int len = adj[src].size();

    for(int i = 0;i<len;i++) {

        int child = adj[src][i];

        if(child != par) {
            bin_lift(child, src);
        }
    }

    return;
}

int find_solution(int node, int level) {
 //   cout << "came so far" << endl;
    int res = 0;

    while(level != 0) {

        for(int i = 19;i>=0;i--) {

            int temp = level & (1 << i);
            int dd = (1<<i);
            if(temp != 0) {
               // cout << "node " << node << "   dd  " << dd << "dp val " << dp[node][dd] << endl;
                res = dp[node][i];
                if(res == -1) break;
                node = res;
                level -= dd;
            }

        }
        if(res == -1) break;

    }
    return res;
}

int main() {

    long long int i,j,t,n,q, val, x, k;

    cin >> n >> q;

    int e[n+2];

    for(int i = 2;i<=n;i++) {

        cin >> val;

        adj[i].push_back(val);
        adj[val].push_back(i);

    }

    for(int i = 0;i<=n;i++) {
        for(int j = 0;j<20;j++) dp[i][j] = -1;
    }
   // cout << "before binary_lift" << endl;
    bin_lift(1, -1);
    //cout << "completed binary_lift " << endl;
    while(q--) {

        cin >> x >> k;
        cout << find_solution(x, k) << endl;

    }

    return 0;
}
