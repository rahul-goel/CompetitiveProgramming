#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <set>
#include <map>

using namespace std;

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	map<int,set<int>> xx, yy;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		xx[x].insert(y);
		yy[y].insert(x);
	}

	for (auto &s : xx) {
		s.second.insert(0);
		s.second.insert(w + 1);
	}
	xx[ax].insert(0);
	xx[ax].insert(w + 1);
	xx[bx].insert(0);
	xx[bx].insert(w + 1);
	for (auto &s : yy) {
		s.second.insert(0);
		s.second.insert(h + 1);
	}
	yy[ay].insert(0);
	yy[ay].insert(h + 1);
	yy[by].insert(0);
	yy[by].insert(h + 1);

	queue<pair<int,int>> q;
	q.push({ax, ay});
	map<pair<int,int>,int> dist;
	dist[{ax, ay}] = 0;

	while (!q.empty() and dist.count({bx, by}) == 0) {
		int cx = q.front().first;
		int cy = q.front().second;
		int cur_dist = dist[{cx, cy}];
		q.pop();

		// up
		{
			auto upit = prev(yy[cy].lower_bound(cx));
			if (*upit != 0) {
				int ux = *upit + 1;
				int uy = cy;
				if (dist.count({ux, uy}) == 0) {
					q.push({ux, uy});
				dist[{ux, uy}] = cur_dist + 1;
					xx[ux].insert(0);
					xx[ux].insert(w + 1);
					yy[uy].insert(0);
					yy[uy].insert(h + 1);
				}
			}
		}

		// down
		{
			auto downit = yy[cy].lower_bound(cx);
			if (*downit != h + 1) {
				int dx = *downit - 1;
				int dy = cy;
				if (dist.count({dx, dy}) == 0) {
				q.push({dx, dy});
					dist[{dx, dy}] = cur_dist + 1;
				xx[dx].insert(0);
					xx[dx].insert(w + 1);
				yy[dy].insert(0);
					yy[dy].insert(h + 1);
				}
			}
		}

		// left
		{
			auto leftit = prev(xx[cx].lower_bound(cy));
			if (*leftit != 0) {
				int lx = cx;
				int ly = *leftit + 1;
				if (dist.count({lx, ly}) == 0) {
				q.push({lx, ly});
					dist[{lx, ly}] = cur_dist + 1;
				xx[lx].insert(0);
					xx[lx].insert(w + 1);
				yy[ly].insert(0);
					yy[ly].insert(h + 1);
				}
			}
		}

		// right
		{
			auto rightit = xx[cx].lower_bound(cy);
			if (*rightit != w + 1) {
				int rx = cx;
				int ry = *rightit - 1;
				if (dist.count({rx, ry}) == 0) {
				q.push({rx, ry});
					dist[{rx, ry}] = cur_dist + 1;
				xx[rx].insert(0);
					xx[rx].insert(w + 1);
				yy[ry].insert(0);
					yy[ry].insert(h + 1);
				}
			}
		}
	}

	if (dist.count({bx, by}) == 0) {
		cout << -1 << endl;
	} else {
		cout << dist[{bx, by}] << endl;
	}

	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
