
#include <bits/stdc++.h>
using namespace std;

const int NUM_COUNTRIES = 20;


int bfs_shortest_path(const vector<vector<int>>& adj, int start, int dest) {
    if (start == dest) {
            return 0;
    }

    vector<int> dist(NUM_COUNTRIES + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);

                if (v == dest) {
                    return dist[v];
                }
            }
        }
    }

    return -1;
}

bool process_test_set(int test_set_num) {
    vector<vector<int>> adj(NUM_COUNTRIES + 1);

    for (int i = 1; i <= NUM_COUNTRIES - 1; ++i) {
        int X;
        if (!(cin >> X)) {
            return false;
        }

        for (int k = 0; k < X; ++k) {
            int J;
            if (!(cin >> J)) return false;

            adj[i].push_back(J);
            adj[J].push_back(i);
        }
    }

    int N;
    if (!(cin >> N)) {
        return false;
    }

    cout << "Test Set #" << test_set_num << endl;

    for (int i = 0; i < N; ++i) {
        int A, B;
        if (!(cin >> A >> B)) return false;

        int min_conquests = bfs_shortest_path(adj, A, B);

        stringstream ss;
        ss << right << setw(2) << A
           << " to "
           << right << setw(2) << B
           << ": "
           << left << min_conquests;

        cout << ss.str() << endl;
    }

    cout << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_set_count = 0;
    while (process_test_set(++test_set_count));

    return 0;
}
