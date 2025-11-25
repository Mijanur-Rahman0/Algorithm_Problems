#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;

struct Edge {
    int u, v;
    ll w;
};

void solve(int set_num, int n) {
    vector<int> busyness(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!(cin >> busyness[i])) return;
    }

    int r;
    if (!(cin >> r)) return;

    vector<Edge> edges;
    for (int i = 0; i < r; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return;

        ll diff = busyness[v] - busyness[u];
        ll weight = diff * diff * diff;

        edges.push_back({u, v, weight});
    }

    int q;
    if (!(cin >> q)) return;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        if (!(cin >> queries[i])) return;
    }

    vector<ll> d(n + 1, INF);
    d[1] = 0;

    for (int i = 1; i < n; ++i) {
        bool updated = false;

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            ll w = edge.w;

            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    vector<bool> neg_cycle(n + 1, false);

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        ll w = edge.w;

        if (d[u] != INF && d[u] + w < d[v]) {
            neg_cycle[v] = true;
        }
    }

    for (int i = 1; i <= n; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;

            if (neg_cycle[u] && !neg_cycle[v]) {
                neg_cycle[v] = true;
                updated = true;
            }
        }
        if (!updated) break;
    }

    cout << "Set #" << set_num << endl;

    for (int query_node : queries) {
        ll result = d[query_node];

        if (result == INF || neg_cycle[query_node]) {
            cout << '?' << endl;
        }
        else if (result < 3) {
            cout << '?' << endl;
        }
        else {
            cout << result << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int set_num = 1;
    while (cin >> n) {
        solve(set_num++, n);
    }

    return 0;
}
