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

int n, k;
vector<vector<int>> mat;
int ans = 0;

set<vector<vector<int>>> track;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int num) {
	if (present(track, mat)) return;
	track.insert(mat);
	if (num == k) {
		ans++;
		return;
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (mat[x][y] == 1) {
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx >= 0 and xx < n and yy >= 0 and yy < n and mat[xx][yy] == 2) {
						mat[x][y] = 2;
						dfs(num + 1);
						mat[x][y] = 1;
					}
				}
			}
		}
	}
}

int solve() {
	cin >> n >> k;

	mat.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) mat[i][j] = (int) (str[j] == '.');
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (mat[i][j]) {
		mat[i][j] = 2;
		dfs(1);
		mat[i][j] = 1;
	}
	cout << ans << endl;
	return 0;
}

signed main() {
	fastio;

	ll t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
