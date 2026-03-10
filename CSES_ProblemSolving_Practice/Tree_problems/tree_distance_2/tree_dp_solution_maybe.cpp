#include <bits/stdc++.h>

using namespace std;

vector <long long int> adj[200008];
long long int temp[200008];
long long int node_cnt[200008];
long long int distance_calc[200008];
long long int sub_tree_distance_calc[200008];

long long int node_calc(int src, int par) {

    int len = adj[src].size();
    long long int res = 1;
    for(int i = 0;i<len;i++) {
        int child = adj[src][i];
        if(child != par) {
           // maxx = max(maxx, 1 + depth_calc(child, src, temp + 1));
           res += node_calc(child, src);
        }
    }

  return node_cnt[src] = res;
}

long long int sub_tree_distance(int src, int par) {

    int len = adj[src].size();
    long long int sum = 0;
    for(int i = 0;i<len;i++) {
        int child = adj[src][i];
        if(par != child) {

            sum += (1 + sub_tree_distance(child, src) + (node_cnt[child] - 1));

        }
    }

    return sub_tree_distance_calc[src] = sum;
}

void tree_distance(int src, int par, int n) {

    distance_calc[src] = sub_tree_distance_calc[src];
  ///  cout << "distance_calc[src]  " << distance_calc[src] <<    "     sub_tree_distance_calc   "   << sub_tree_distance_calc[src] << endl;
    int len = adj[src].size();
  //  distance_calc[src] = sub_tree_distance_calc[src];
    for(int i = 0;i<len;i++) {
        int child = adj[src][i];
        if(par != child) {

            sub_tree_distance_calc[child] = (distance_calc[src] - node_cnt[child]) + (n - node_cnt[child]);
            tree_distance(child, src, n);
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

    node_calc(1, -1);
  //  for(int i = 1;i<=n;i++) cout << "node i " << i << "  and node_cnt " << node_cnt[i] << endl;
    sub_tree_distance(1, -1);
   // for(int i = 1;i<=n;i++) cout << "node i " << i << "  and sub_tree_distance " << sub_tree_distance_calc[i] << endl;
    tree_distance(1, -1, n);
    for(int i = 1;i<=n;i++) cout << distance_calc[i] << " ";
    cout << endl;
    return 0;
}
