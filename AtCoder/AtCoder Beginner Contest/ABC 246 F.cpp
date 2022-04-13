#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

long long MOD = 998244353;

long long power(long long x, long long y) {
	long long ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ret;
}

void solve() {
	int n, l;
	cin >> n >> l;

	vector<string> vec(n);
	vector<int> alph(n);
	for (string &s : vec) cin >> s;
	for (int i = 0; i < n; ++i) {
		for (char x : vec[i]) {
			alph[i] |= (1 << (x - 'a'));
		}
	}

	long long ans = 0;
	for (int mask = 1; mask < (1 << n); ++mask) {
		int ch = (1 << 26) - 1;
		for (int i = 0; i < n; ++i) {
			if (mask >> i & 1) {
				ch &= alph[i];
			}
		}

		int num = __builtin_popcount(ch);
		long long cnt = power(num, l);
		if ((__builtin_popcount(mask)) & 1) ans = (ans + cnt) % MOD;
		else ans = (ans - cnt + MOD) % MOD;
	}

	cout << ans << endl;

	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
