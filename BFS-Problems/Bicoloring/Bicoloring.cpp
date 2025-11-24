#include <bits/stdc++.h>

using namespace std;

bool is_bicolorable(int n, const vector<vector<int>>& adj) {
    if (n <= 1) {
        return true;
    }

    vector<int> colors(n, 0);

    queue<int> q;

    int start_node = 0;
    q.push(start_node);
    colors[start_node] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int neighbor_color = 3 - colors[u];

        for (int v : adj[u]) {
            if (colors[v] == 0) {
                colors[v] = neighbor_color;
                q.push(v);
            } else if (colors[v] == colors[u]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n && n != 0) {
        int l;
        cin >> l;

        vector<vector<int>> adj(n);

        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (is_bicolorable(n, adj)) {
            cout << "BICOLORABLE." << "\n";
        } else {
            cout << "NOT BICOLORABLE." << "\n";
        }
    }

    return 0;
}
