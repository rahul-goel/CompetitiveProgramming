/*
   Created by Rahul Goel.
   */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*******************************************************************************/
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*******************************************************************************/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template < typename T, typename... Args >
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a * mod_prod(args...))%MOD; }
/*******************************************************************************/
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
   Code begins after this.
   */

ll solve() {
	ll n;
	cin >> n;
	vector<ll> b(n);

	for (ll &x : b) cin >> x, --x;
	vector<ll> ans;
	map<ll,vector<ll>> mp;
	for (ll i = 0; i < n; i++) {
		mp[b[i]].push_back(i);
	}

	while (true) {
		vector<ll> tmp(n, -1);
		vector<bool> done(n);
		for (auto &[num, v] : mp) {
			ll choice = rand() % v.size();
			tmp[v[choice]] = num;
			done[num] = true;
		}

		vector<ll> nd;
		for (ll i = 0; i < n; i++) {
			if (not done[i]) {
				nd.push_back(i);
			}
		}
		random_shuffle(nd.begin(), nd.end());
		for (ll i = 0; i < n; i++) {
			if (tmp[i] == -1) {
				tmp[i] = nd.back();
				nd.pop_back();
			}
		}

		bool ok = true;
		for (ll i = 0; i < n; i++) {
			if (tmp[i] == i) {
				ok = false;
				break;
			}
		}

		if (ok) {
			ans = tmp;
			break;
		}
	}

	ll cnt = 0;
	for (ll i = 0; i < n; i++) cnt += (ll) (b[i] == ans[i]);

	cout << cnt << endl;
	for (ll i = 0; i < n; i++) {
		cout << ans[i] + 1<< " ";
	}
	cout << endl;

	return 0;
}

signed main() {
	fastio;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
