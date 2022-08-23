#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const ll LINF = 1e9;

struct Dijkstra {
	using pii = pair<ll,ll>;

	vector<vector<pii>> &adj;
	vector<ll> par;
	vector<ll> dist;
	ll src;

	Dijkstra(vector<vector<pii>> &adj, ll src) : adj(adj), src(src) {
		ll n = adj.size();
		par.assign(n, -1);
		dist.assign(n, LINF);

		priority_queue<pii, vector<pii>, greater<pii>> q;

		dist[src] = 0;
		q.push({0, src});

		while (q.size()) {
			ll v = q.top().second;
			ll dist_v = q.top().first;
			q.pop();

			if (dist_v != dist[v]) continue;

			for (pii edge : adj[v]) {
				ll to = edge.first;
				ll len = edge.second;

				if (dist[v] + len < dist[to]) {
					dist[to] = dist[v] + len;
					par[to] = v;
					q.push({dist[to], to});
				}
			}
		}
	}

	vector<ll> getpath(ll dest) {
		vector<ll> path;
		for (ll u = dest; u != -1; u = par[u]) {
			path.push_back(u);
		}
		reverse(path.begin(), path.end());
		return path;
	}
};
