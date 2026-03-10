#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200008];
int temp[200008];


void dfs(int src, int par, int val) {

    int len = adj[src].size();

    temp[src] = max(temp[src], val);

    for(int i = 0;i<len;i++) {
        int child = adj[src][i];
        if(child != par) {
            dfs(child, src, val + 1);
        }
    }
    return;
}

int main() {


    int i,j,t,n, p, q;

    cin >> n;

    for(int i = 0;i<n-1;i++) {
        cin >> p >> q;

        adj[p].push_back(q);
        adj[q].push_back(p);

    }

    dfs(1, -1, 0);
    int maxx = 0;
    int node = -1;
    for(int i = 1;i<=n;i++) {
        if(temp[i] >= maxx) {
            maxx = temp[i];
            node = i;
        }
    }
    dfs(node, -1, 0);
    for(int i = 1;i<=n;i++) {
        if(temp[i] >= maxx) {
            maxx = temp[i];
            node = i;
        }
    }
    dfs(node, -1, 0);
    for(int i = 1;i<=n;i++) cout << temp[i] << " ";
    cout << endl;

    return 0;
}
