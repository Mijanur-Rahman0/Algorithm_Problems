#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> d(n + 1, INF);
    vector<int> p(n + 1, -1);

    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll cur_d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cur_d > d[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int len = edge.second;

            if (d[u] + len < d[v]) {
                d[v] = d[u] + len;
                p[v] = u;
                pq.push({d[v], v});
            }
        }
    }

    if (d[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = p[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
