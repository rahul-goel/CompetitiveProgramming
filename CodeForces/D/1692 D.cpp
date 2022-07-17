#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int clocktotime(string str) {
	int time = 0;
	time += stoi(str.substr(0, 2)) * 60;
	time += stoi(str.substr(3, 2));
	return time;
}

string timetoclock(int time) {
	int hours = time / 60;
	int mins = time % 60;
	string hours_str = to_string(hours);
	string mins_str = to_string(mins);
	if (hours_str.size() == 1) hours_str = "0" + hours_str;
	if (mins_str.size() == 1) mins_str = "0" + mins_str;
	return hours_str + ":" + mins_str;
}

bool ispalindrome(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int solve() {
	string start_str;
	int rep;
	cin >> start_str >> rep;

	int start = clocktotime(start_str);

	int cnt = 0;
	vector<int> vis(1440);
	int cnt_vis = 0;
	for (int i = 0; i < 1440 * 1440; i += rep) {
		if (cnt_vis == 1440) {
			break;
		}
		int cur = (start + i) % 1440;
		if (vis[cur]) continue;
		vis[cur] = 1;
		cnt_vis += 1;
		string cur_str = timetoclock(cur);
		cnt += ispalindrome(cur_str);
	}

	cout << cnt << endl;

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
