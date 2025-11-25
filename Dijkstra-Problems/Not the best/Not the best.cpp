#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

void solve(int t) {
    int n, r;
    if (!(cin >> n >> r)) return;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < r; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<ll>> d(n + 1, vector<ll>(2, INF));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    d[1][0] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d[u][1] != INF && cost > d[u][1]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            ll new_cost = cost + w;

            if (new_cost < d[v][0]) {
                d[v][1] = d[v][0];
                d[v][0] = new_cost;
                pq.push({d[v][0], v});
                pq.push({d[v][1], v});
            } else if (new_cost > d[v][0] && new_cost < d[v][1]) {
                d[v][1] = new_cost;
                pq.push({d[v][1], v});
            }
        }
    }

    cout << "Case " << t << ": " << d[n][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}
