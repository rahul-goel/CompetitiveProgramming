#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <set>
#include <array>

using namespace std;

const int INF = 1e9;

int dx[] = {1, -1, 1, -1};
int dy[] = {-1, 1, 1, -1};

void solve() {
	int n;
	cin >> n;
	int ax, ay;
	cin >> ax >> ay;
	int bx, by;
	cin >> bx >> by;

	--ax, --ay, --bx, --by;

	vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
	vector<string> mat(n);

	for (string &s : mat) cin >> s;

	deque<array<int,3>> dq;
	for (int i = 0; i < 4; ++i) {
		int nx = ax + dx[i];
		int ny = ay + dy[i];
		if (!(nx >= 0 and nx < n)) continue;
		if (!(ny >= 0 and ny < n)) continue;
		if (mat[nx][ny] == '#') continue;
		dist[nx][ny][i] = 1;
		dq.push_back({nx, ny, i});
	}

	while (!dq.empty()) {
		int x = dq.front()[0];
		int y = dq.front()[1];
		int dir = dq.front()[2];
		dq.pop_front();

		if (x == bx and y == by) {
			cout << dist[x][y][dir] << endl;
			return;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx >= 0 and nx < n)) continue;
			if (!(ny >= 0 and ny < n)) continue;
			if (mat[nx][ny] == '#') continue;

			int new_dist = dist[x][y][dir] + (dir != i);
			if (new_dist < dist[nx][ny][i]) {
				dist[nx][ny][i] = new_dist;
				if (dir == i) {
					dq.push_front({nx, ny, i});
				} else {
					dq.push_back({nx, ny, i});
				}
			}
		}
	}

	cout << -1 << endl;

	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
