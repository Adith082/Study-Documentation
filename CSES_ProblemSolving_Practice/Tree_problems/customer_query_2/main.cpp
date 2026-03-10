#include <bits/stdc++.h>

using namespace std;

int dp[200005][20];
vector <int> adj[200005];
int node_level[200005];
int parent[200005];

void bin_lift_and_level_calc(int src, int par, int lvl) {

   // cout << "paths " << src << endl;

        dp[src][0] = par;
        parent[src] = par;
        node_level[src] = lvl;
        for(int i = 1;i<20;i++) {
            if(dp[src][i-1] != -1)
              dp[src][i] = dp[dp[src][i - 1]][i - 1];
            else dp[src][i] = -1;
        }


    int len = adj[src].size();

    for(int i = 0;i<len;i++) {

        int child = adj[src][i];

        if(child != par) {
            bin_lift_and_level_calc(child, src, lvl + 1);
        }
    }

    return;
}

int level_up_node_calc(int node, int lvl) {
     for(int i = 0;i<20;i++) {
                int temp = lvl & (1<<i);
                int position_val = (1<<i);
                if(temp != 0) {

///cout << "node " <<  node << "   and the level   " << lvl << endl;

                    node = dp[node][i];
                   // cout << " k_level_boss_node  ,... " << node << endl;
                    lvl -= position_val;
                }
            }
            return node;
}

int find_solution(int node1, int node2) {

    int lv1 = node_level[node1];
    int lv2 = node_level[node2];

    if(lv1>lv2) {
        node1 = level_up_node_calc(node1, lv1 - lv2);
    }   else if(lv1 < lv2) {
        node2 = level_up_node_calc(node2, lv2 - lv1);
    }

    if(node1 == node2) return node1;
    for(int i = 19;i>=0;i--) {
        if(dp[node1][i] != dp[node2][i]) {
            node1 = dp[node1][i];
            node2 = dp[node2][i];
        }
    }

    return dp[node1][0];
}

int main() {

    long long int i,j,t,n,q, val, x, k, y;

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
    bin_lift_and_level_calc(1, -1, 0);
    //cout << "completed binary_lift " << endl;
    while(q--) {

        cin >> x >> y;
        cout << find_solution(x, y) << endl;

    }

    return 0;
}
