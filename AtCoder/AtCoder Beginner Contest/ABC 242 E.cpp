#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;
using ll = long long;

const ll MOD = 998244353;


void solve() {
	int n;
	string str;
	cin >> n;
	cin >> str;

	ll ans = 0;
	int half = (n + 1) / 2;
	for (int i = 0; i < half; ++i) {
		ans = (ans * 26ll) % MOD;
		ans = (ans + str[i] - 'A') % MOD;
	}

	string pal = str;
	int l = 0, r = n - 1;
	while (l < r) {
		pal[r] = pal[l];
		++l, --r;
	}

	if (pal <= str) ans = (ans + 1) % MOD;

	cout << ans << endl;
	return;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
