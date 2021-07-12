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

struct Word {
	ll len;
	ll cnt;
	string s;
};

string get_first(string &s) {
	if (s.size() < 3) {
		return s;
	} else {
		return s.substr(0, 3);
	}
}

string get_last(string &s) {
	if (s.size() < 3) {
		return s;
	} else {
		return s.substr(s.size() - 3, 3);
	}
}

ll stringcnt(string a) {
	ll ret = 0;
	for (ll i = 0; i < (ll) a.size(); i++) {
		if (a.substr(i, 4) == "haha") {
			ret++;
		}
	}
	return ret;
}

Word combine(Word &a, Word &b) {
	Word ret;
	ret.len = a.len + b.len;
	ret.s = a.s + b.s;
	ret.cnt = a.cnt + b.cnt + stringcnt(get_last(a.s) + get_first(b.s));
	if (ret.s.size() >= 7) {
		ret.s = get_first(ret.s) + "$" + get_last(ret.s);
	}
	return ret;
}

ll solve() {
	ll n;
	cin >> n;

	map<string, Word> mp;
	string last;
	while (n--) {
		string left;
		cin >> left;
		string assign;
		cin >> assign;
		last = left;

		if (assign == ":=") {
			string right;
			cin >> right;
			Word word;
			word.len = right.size();
			word.cnt = stringcnt(right);
			word.s = right;
			mp[left] = word;
		} else if (assign == "=") {
			string right1, right2, plus;
			cin >> right1 >> plus >> right2;
			mp[left] = combine(mp[right1], mp[right2]);
		}
	}

	cout << mp[last].cnt << endl;
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
