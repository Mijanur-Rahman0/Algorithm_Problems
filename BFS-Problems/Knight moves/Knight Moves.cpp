#include <bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 8;

const int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};


pair<int, int> toCoords(const string& square) {
    int col = square[0] - 'a';
    int row = square[1] - '1';
    return {row, col};
}

bool isValid(int r, int c) {
    return (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE);
}

int minKnightMoves(const string& start_sq, const string& end_sq) {
    pair<int, int> start = toCoords(start_sq);
    pair<int, int> end = toCoords(end_sq);

    if (start == end) {
        return 0;
    }

    int dist[BOARD_SIZE][BOARD_SIZE];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;

    int start_r = start.first;
    int start_c = start.second;

    q.push({start_r, start_c});
    dist[start_r][start_c] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;
        int d = dist[r][c];

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc) && dist[nr][nc] == -1) {
                dist[nr][nc] = d + 1;

                if (nr == end.first && nc == end.second) {
                    return d + 1;
                }

                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start_sq, end_sq;

    while (cin >> start_sq >> end_sq) {
        int moves = minKnightMoves(start_sq, end_sq);

        cout << "To get from " << start_sq << " to " << end_sq << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
