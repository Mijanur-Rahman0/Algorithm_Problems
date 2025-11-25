#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

typedef tuple<int, int, int> Edge;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges.emplace_back(u, v, t);
    }

    vector<ll> d(n, INF);
    d[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool updated_in_pass = false;

        for (const auto& edge : edges) {
            int u, v, t;
            tie(u, v, t) = edge;

            if (d[u] != INF) {
                if (d[u] + t < d[v]) {
                    d[v] = d[u] + t;
                    updated_in_pass = true;
                }
            }
        }

        if (!updated_in_pass) break;
    }

    bool possible = false;

    for (const auto& edge : edges) {
        int u, v, t;
        tie(u, v, t) = edge;

        if (d[u] != INF) {
            if (d[u] + t < d[v]) {
                possible = true;
                break;
            }
        }
    }

    if (possible) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (cin >> c) {
        while (c--) {
            solve();
        }
    }
    return 0;
}
