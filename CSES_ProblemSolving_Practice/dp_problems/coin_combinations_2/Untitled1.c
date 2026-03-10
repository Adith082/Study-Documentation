# sieve prime calculation code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}


# check if a number is prime or not using big of root n time complexity algo

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;

    if (isPrime(n))
        cout << "Prime\n";
    else
        cout << "Not Prime\n";

    return 0;
}


# find divisors using big of root n complexity algo

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> divisors;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    for (auto d : divisors) {
        cout << d << " ";
    }

    return 0;
}


# find p^q in logn complexity

#include <bits/stdc++.h>
using namespace std;

long long power(long long p, long long q) {
    long long result = 1;

    while (q > 0) {
        if (q % 2 == 1) {     // If q is odd
            result *= p;
        }

        p *= p;               // Square the base
        q /= 2;               // Divide exponent by 2
    }

    return result;
}

int main() {
    long long p, q;
    cin >> p >> q;

    cout << power(p, q);

    return 0;
}




# basic segment tree traversal code

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

long long arr[MAXN];
long long seg[4 * MAXN];   // 4*N is safe size

// 🔹 Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

// 🔹 Query sum in range [l, r]
long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;  // no overlap

    if (l <= start && end <= r)
        return seg[node];  // complete overlap

    int mid = (start + end) / 2;

    long long leftSum = query(2 * node, start, mid, l, r);
    long long rightSum = query(2 * node + 1, mid + 1, end, l, r);

    return leftSum + rightSum;  // partial overlap
}

// 🔹 Update index idx to new value val
void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        arr[idx] = val;
        seg[node] = val;
    } else {
        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    cout << query(1, 0, n - 1, 1, 3) << endl; // example query

    update(1, 0, n - 1, 2, 10); // example update

    return 0;
}



# basic bfs traversal code

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";   // Process node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;   // n = nodes, m = edges
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this if directed graph
    }

    bfs(1);   // Start BFS from node 1

    return 0;
}



# dfs non-grid

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }

    dfs(1);
}

# dfs grid

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            !visited[nx][ny] && grid[nx][ny] == '.') {

            dfs(nx, ny);
        }
    }
}

# kruskals algo (Minimam spanning tree)

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

const int MAXN = 100005;
int parent[MAXN];

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    long long mstWeight = 0;

    for (auto e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            mstWeight += e.w;
            unionSet(e.u, e.v);
        }
    }

    cout << mstWeight;
}


# prims algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> adj[MAXN]; // {neighbor, weight}
bool visited[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, 1}); // {weight, node}

    long long mstWeight = 0;

    while (!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mstWeight += w;

        for (auto [neighbor, weight] : adj[node]) {
            if (!visited[neighbor]) {
                pq.push({weight, neighbor});
            }
        }
    }

    cout << mstWeight;
}


# bellman-ford algo

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != LLONG_MAX &&
                dist[e.u] + e.w < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Negative cycle check
    for (auto e : edges) {
        if (dist[e.u] != LLONG_MAX &&
            dist[e.u] + e.w < dist[e.v]) {

            cout << "Negative cycle detected";
        }
    }
}


# Dijkstra algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> adj[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}



# floyed warshall algo

# #include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
}



# multi-source bfs

void multiSourceBFS(vector<int> sources, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    for (int src : sources) {
        q.push(src);
        dist[src] = 0;
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}


# 0 1 BFS edges with weight 0 or 1

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> adj[MAXN];  // {neighbor, weight}
int dist[MAXN];

void zeroOneBFS(int start, int n) {
    deque<int> dq;

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[start] = 0;
    dq.push_front(start);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;

                if (weight == 0)
                    dq.push_front(neighbor);
                else
                    dq.push_back(neighbor);
            }
        }
    }
}


# bfs with distance array

void bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

# bfs shortest path unweighted graph

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
}


# bfs for grid

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && grid[nx][ny] == '.') {

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

