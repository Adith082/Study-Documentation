#include <bits/stdc++.h>
using namespace std;
long long node_value[200009];
vector <long long> adj[200009];
long long in_time_and_value[200009];
long long in_time[200009];
long long subtree_size[200009];
long long timee = 0;
const long long MAXN = 200005;
long long tree[4 * MAXN];
long long n;
void build(long long tree[], long long node, long long start, long long end) {

    if(start == end) {
        tree[node] = in_time_and_value[start];
        return;
    }

    long long mid = (start + end)/2;
    build(tree, node * 2, start, mid);
    build(tree, node * 2  +  1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}
void update(long long node, long long start, long long end, long long idx, long long val) {

    if(start == end) {
        tree[node] = val;
        return;
    }

    long long mid = (start + end) / 2;

    if(idx <= mid) {
        update(node * 2, start, mid, idx, val);
    }   else{
        update(node * 2 + 1, mid + 1, end, idx, val);
    }

     tree[node] = tree[node * 2] + tree[node * 2 + 1];

}
long long query(long long node, long long l, long long r, long long start, long long end) {

    if((r < start) || (l > end)) {
        return 0;
    }

    if((l <= start) && (r >= end)) {
        return tree[node];
    }

    long long mid = (start + end)/2;

    long long left_tree_sum = query(node * 2, l, r, start, mid);
    long long right_tree_sum = query(node * 2 + 1, l, r, mid + 1, end);

    return left_tree_sum + right_tree_sum;

}
long long dfs(long long src, long long par) {

    in_time[src] = ++timee;

    long long sizee = 1;

    long long len = adj[src].size();

    for(long long i = 0;i<len;i++) {

        long long child = adj[src][i];

        if(child != par) {

            sizee += dfs(child, src);

        }
    }

        return subtree_size[src] = sizee;
}
int main() {

    long long i,t,n,q, u, v, s, x, qq;

    cin >> n >> q;

    for(long long i = 1;i<=n;i++) cin >> node_value[i];
    for(long long i = 1;i<=(n - 1) ;i++) {

        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(1, -1);

    for(long long i = 1;i<=n;i++) {
        in_time_and_value[in_time[i]] = node_value[i];
    }

    build(tree, 1, 1, n);

    for(long long i = 1;i<=q;i++) {

        cin >> qq;
        if(qq == 1) {
            cin >> s >> x;
            in_time_and_value[in_time[s]] = x;
            update(1, 1, n, in_time[s], x);

        }   else {
            cin >> s;
            long long l = in_time[s];
            long long r = in_time[s] + (subtree_size[s] - 1);
            cout << query(1, l, r, 1, n) << endl;
        }

    }

    return 0;
}
