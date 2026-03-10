#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200008];
int temp[200008];
int down_path[200008];
int diameter[200008];

int depth_calc(int src, int par, int temp) {

    int len = adj[src].size();
    int maxx = 0;
    int cnt = 0;
    for(int i = 0;i<len;i++) {
        int child = adj[src][i];
        if(child != par) {
            cnt++;
            maxx = max(maxx, 1 + depth_calc(child, src, temp + 1));
        }
    }

    if(cnt >= 1) return down_path[src] = maxx;
    return down_path[src] = 0;

}


int find_diameter(int src, int par) {

    int len = adj[src].size();
    vector <int> childs_down_paths;
    int maxx = 0;

    for(int i = 0;i<len; i++) {

        int child = adj[src][i];

        if(child != par) {
            maxx = max(maxx, find_diameter(child, src));
            childs_down_paths.push_back(down_path[child]);
        }
    }

    sort(childs_down_paths.begin(), childs_down_paths.end());

    int ll = childs_down_paths.size();

    if(ll >= 2) {
        return diameter[src] = max(maxx, (2 + childs_down_paths[ll - 1] + childs_down_paths[ll - 2]));
    }  else if(ll == 1) {
        return diameter[src] = max(maxx, (1 + childs_down_paths[0]));
    }

    return diameter[src] = maxx;
}

int main() {


    int i,j,t,n, p, q;

    cin >> n;

    for(int i = 0;i<n-1;i++) {
        cin >> p >> q;

        adj[p].push_back(q);
        adj[q].push_back(p);

    }

    depth_calc(1, -1, 0);
    cout << find_diameter(1, -1) << endl; // really didn't need to store the value in diameter array as it's a tree traversal having
    // parent child relationship
 //   cout << diameter[1] << endl;
    return 0;
}
