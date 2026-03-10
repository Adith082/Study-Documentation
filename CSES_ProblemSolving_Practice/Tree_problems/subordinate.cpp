//IN THE NAME OF ALLAH THE MOST MERCIFUL, THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];
int dp[200005];

int dfs(int src, int par) {


    int res = 1;
    for(int i = 0;i<adj[src].size();i++) {

        int child = adj[src][i];
        if(child != par) {
            res += dfs(child, src);
        }

    }
    return dp[src] = res;
}

int main() {

    int i, j, n, val;
    cin >> n;
    int a[n + 5];
    for(int i = 2;i<=n;i++) {
        cin >> val;
        adj[i].push_back(val);
        adj[val].push_back((i));
    }
    dfs(1, -1);
    for(int i = 1;i<=n;i++) cout << (dp[i] - 1) << " ";
    cout << endl;

    return 0;
}
