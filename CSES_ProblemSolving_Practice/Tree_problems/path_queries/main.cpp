#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
long long node_value[MAXN];
vector<long long> adj[MAXN];
long long in_time_and_value[MAXN];
long long in_time[MAXN];
long long out_time[MAXN];
long long timee = 0;
long long tree[4 * MAXN];

void build(long long node, long long start, long long end) {
    if(start == end) {
        tree[node] = in_time_and_value[start];
        return;
    }
    long long mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(long long node, long long start, long long end, long long idx, long long val) {
    if(start == end) {
        tree[node] = val;
        return;
    }
    long long mid = (start + end) / 2;
    if(idx <= mid)
        update(node * 2, start, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(long long node, long long l, long long r, long long start, long long end) {
    if(r < start || l > end) return 0;
    if(l <= start && r >= end) return tree[node];
    long long mid = (start + end) / 2;
    long long left_sum  = query(node * 2,     l, r, start, mid);
    long long right_sum = query(node * 2 + 1, l, r, mid + 1, end);
    return left_sum + right_sum;
}

void dfs(long long src, long long par) {
    in_time[src] = ++timee;
    for(long long i = 0; i < (long long)adj[src].size(); i++) {
        long long child = adj[src][i];
        if(child != par) {
            dfs(child, src);
        }
    }
    out_time[src] = timee;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q;
    cin >> n >> q;

    for(long long i = 1; i <= n; i++) cin >> node_value[i];

    for(long long i = 1; i <= n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for(long long i = 1; i <= n; i++) {
        in_time_and_value[in_time[i]]      += node_value[i];  // +value at in_time
        in_time_and_value[out_time[i] + 1] -= node_value[i];  // -value at out_time + 1
    }

    build(1, 1, n + 1);  // size is n+1 now

    for(long long i = 1; i <= q; i++) {
        long long qq;
        cin >> qq;
        if(qq == 1) {
            long long s, x;
            cin >> s >> x;
            long long old_val = node_value[s];
            long long new_val = x;
            node_value[s] = x;

            in_time_and_value[in_time[s]]      += (new_val - old_val);
            in_time_and_value[out_time[s] + 1] -= (new_val - old_val);

            update(1, 1, n + 1, in_time[s],      in_time_and_value[in_time[s]]);
            update(1, 1, n + 1, out_time[s] + 1, in_time_and_value[out_time[s] + 1]);

        } else {
            long long s;
            cin >> s;
            cout << query(1, 1, in_time[s], 1, n + 1) << "\n";
        }
    }

    return 0;
}
