#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// disjoint set "find" function with path compression
int find(int x) {
    if (x < 0) return -1;
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> tickets(n), customers(m);

    for (int i = 0; i < n; i++) cin >> tickets[i];
    for (int i = 0; i < m; i++) cin >> customers[i];

    sort(tickets.begin(), tickets.end());

    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int t : customers) {
        // find largest ticket <= t
        int idx = upper_bound(tickets.begin(), tickets.end(), t) - tickets.begin() - 1;

        if (idx < 0) {
            cout << -1 << "\n";
            continue;
        }

        idx = find(idx);
        if (idx == -1) {
            cout << -1 << "\n";
        } else {
            cout << tickets[idx] << "\n";
            parent[idx] = find(idx - 1);  // union with left neighbor
        }
    }
    return 0;
}
