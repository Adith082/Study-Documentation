#include <bits/stdc++.h>
using namespace std;

const long long NEG = -1e18;

long long dp[1005][1 << 10];
bool vis[1005][1 << 10];

long long solve(int i, int n, int m, int deli[], int nutri[], int mask) {

    if(i == n) {
        if(mask == (1 << m) - 1)  // all nutrients odd
            return 0;
        return NEG;              // invalid
    }

    if(vis[i][mask]) return dp[i][mask];
    vis[i][mask] = true;

    // Option 1: skip item
    long long notTake = solve(i + 1, n, m, deli, nutri, mask);

    // Option 2: take item
    long long take = deli[i] +
        solve(i + 1, n, m, deli, nutri, mask ^ nutri[i]);

    return dp[i][mask] = max(notTake, take);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {

        int n, m;
        cin >> n >> m;

        int deli[n];
        int nutri[n];

        for(int i = 0; i < n; i++) {
            int d, c;
            cin >> d >> c;

            deli[i] = d;

            int val = 0;
            for(int k = 0; k < c; k++) {
                int v;
                cin >> v;
                val |= (1 << (v - 1));   // IMPORTANT: v-1
            }
            nutri[i] = val;
        }

        // reset dp
        for(int i = 0; i <= n; i++) {
            for(int mask = 0; mask < (1 << m); mask++) {
                vis[i][mask] = false;
            }
        }

        long long ans = solve(0, n, m, deli, nutri, 0);

        if(ans < 0) ans = 0;  // if impossible

        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}
