#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];

int edge_cnt;

int dp[200005];

int res[200005];

void dfs(int src, int par) {

for(int i = 0;i<adj[src].size();i++) {

    int child = adj[src][i];
    if(child != par) {
        dfs(child, src);
    }
}


   for(int i = 0;i<adj[src].size();i++) {
    int child = adj[src][i];
    if(child != par) {
        if((res[child] == 0) && (res[src] == 0)) {
            edge_cnt++;
            res[src] = 1;
            res[child] = 1;
            break;
        }
    }
}
   return;
}

int main() {

int i, j, n, val, p, q;

    cin >> n;

    edge_cnt = 0;

    for(int i = 0;i<=n;i++) res[i] = 0;

    for(int i = 1;i<=(n - 1);i++) {

        cin >> p >> q;

        adj[p].push_back(q);

        adj[q].push_back((p));
}
    dfs(1, -1);

    cout << edge_cnt << endl;

return 0;

}
