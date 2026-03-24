#include <bits/stdc++.h>


// USING THE HELP OF LCA AND DIFFERENCE ARRAY TECHNOQUE
using namespace std;

int dp[200005][20];
vector <int> adj[200005];
int pref[200005];
int node_level[200005];
int parent[200005];

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


int find_lca(int node1, int node2) {

    int lv1 = node_level[node1];
    int lv2 = node_level[node2];


    if(lv1>lv2) {
        node1 = level_up_node_calc(node1, lv1 - lv2);
    }   else if(lv1 < lv2) {
        node2 = level_up_node_calc(node2, lv2 - lv1);
    }

    if(node1 == node2) {
        // pref[node1] -= 1;
        // pref[dp[node1][0]] -= 1;
        return node1;
    }
    for(int i = 19;i>=0;i--) {
        if(dp[node1][i] != dp[node2][i]) {
            node1 = dp[node1][i];
            node2 = dp[node2][i];
        }
    }
    // pref[node1] -= 1;
    // if(dp[node1][0] != -1) pref[dp[node1][0]] -= 1;
    return dp[node1][0];

}


void track_path_using_lca(int node1, int node2) {
    int lca = find_lca(node1, node2);
    pref[node1] += 1;
    pref[node2] += 1;
    pref[lca] -= 1;
    if(dp[lca][0] != -1) pref[dp[lca][0]] -= 1;
    return;
}

void find_subtree_sum(int src, int par)  {

    int len = adj[src].size();
    for(int i = 0; i<len; i++) {

        int child = adj[src][i];
        if(child != par) {
            find_subtree_sum(child, src);
            pref[src] += pref[child];
        }
    }
}


int main() {


   long long int i,j,t,n,m, p,q, a, b;

   cin >> n >> m;

   for(int i = 0;i<n-1;i++) {

       cin >> p >> q;

       adj[p].push_back(q);
       adj[q].push_back(p);

   }

    for(int i = 0;i<=n;i++) {
        for(int j = 0;j<20;j++) dp[i][j] = -1;
    }

    bin_lift_and_level_calc(1, -1, 0);
    //cout << "completed binary_lift " << endl;
    while(m--) {

        cin >> a >> b;
        track_path_using_lca(a, b);
    }

    find_subtree_sum(1, -1);
    for(int i = 1;i<=n;i++) cout << pref[i] << " ";
    cout << endl;

    return 0;
}
