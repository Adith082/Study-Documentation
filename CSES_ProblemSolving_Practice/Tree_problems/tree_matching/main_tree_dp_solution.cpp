
/*

this is the accepted code from claude code. this version is more clean and clear.

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
int dp[200005][2];

int dfs(int src, int par, int fl) {
    if(dp[src][fl] != -1) return dp[src][fl];

    if(fl == 0) {
        int res = 0;
        for(int i = 0; i < adj[src].size(); i++) {
            int child = adj[src][i];
            if(child != par) {
                res += max(dfs(child, src, 0), dfs(child, src, 1));
            }
        }
        return dp[src][fl] = res;
    }

    // fl == 1: src is matched to exactly one child
    // First compute base (as if unmatched)
    int base = 0;
    vector<pair<int,int>> children; // {child_node, max(dp[child][0], dp[child][1])}

    for(int i = 0; i < adj[src].size(); i++) {
        int child = adj[src][i];
        if(child != par) {
            int best = max(dfs(child, src, 0), dfs(child, src, 1));
            base += best;
            children.push_back({child, best});
        }
    }

    // Try matching src with each child v
    // gain = 1 + dp[v][0] - max(dp[v][0], dp[v][1])
    int maxx = 0;
    for(auto& [child, best] : children) {
        int gain = 1 + dfs(child, src, 0) - best;
        maxx = max(maxx, gain);
    }

    return dp[src][fl] = base + maxx;
}

int main() {
    int n, p, q;
    cin >> n;

    for(int i = 1; i < n; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    memset(dp, -1, sizeof(dp));
    cout << max(dfs(1, -1, 0), dfs(1, -1, 1)) << endl;

    return 0;
}
*/

// the below is my implementated version of code
#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
int edge_cnt;
int dp[200005][3];
int res[200005];
int dfs(int src, int par, int fl) {

    if(dp[src][fl] != -1) {
        return dp[src][fl];
    }

    if(fl == 0) {
       int res = 0;
       for(int i = 0;i<adj[src].size();i++) {
       int child = adj[src][i];
       if(child != par) {
        res += max(dfs(child, src, 0), dfs(child, src, 1));
       }
}

      return dp[src][fl] = res;
    }

     // I guess, could have done it using one loop
        int sum = 0;
        vector < pair <int, int > > pref_vec;
        for(int i = 0;i<adj[src].size();i++) {

            int child = adj[src][i];

            if(child != par) {
                int best_ = max(dfs(child, src, 0), dfs(child, src, 1));
                sum += best_;
                pref_vec.push_back({child, best_});
            }
        }

        int maxx = 0;
        int len = pref_vec.size();
        for(int i = 0;i<pref_vec.size(); i++) {

            int temp = (1 + dfs(pref_vec[i].first, src, 0)) - pref_vec[i].second;
            maxx = max(maxx, temp);
        }

        return dp[src][fl] = maxx + sum;
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
    int maxx = 0;
    for(int i = 0;i<=n;i++) for(int j = 0;j<=2;j++) dp[i][j] = -1;
    for(int i = 0;i<=1;i++) {
        maxx = max({maxx, dfs(1, -1, 0), dfs(1, -1, 1)});
    }

    cout << maxx << endl;

    return 0;
}

//take a look at the above code. I tried to come up with a recursive dp solution. do you notice any problem in the above code? kindly point it out and fix in the above code and give the code
