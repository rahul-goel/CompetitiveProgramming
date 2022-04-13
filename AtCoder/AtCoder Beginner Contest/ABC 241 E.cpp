#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;

	vector<long long> vec(n);
	vector<bool> vis(n);
	for (long long &x : vec) cin >> x;

	long long cur = 0;
	long long cnt = 0;
	long long sum = 0;
	vector<long long> seq;
	while (!vis[cur]) {
		vis[cur] = true;
		seq.push_back(cur);
		sum += vec[cur];
		++cnt;
		cur = sum % n;
	}

	long long chain = find(seq.begin(), seq.end(), cur) - seq.begin();
	long long ans = 0;

	if (k <= chain) {
		for (long long i = 0; i < k; ++i) ans += vec[seq[i]];
		cout << ans << endl;
		return;
	}

	for (long long i = 0; i < chain; ++i) {
		ans += vec[seq[i]];
	}

	k -= chain;
	long long rep = 0;
	for (long long i = chain; i < seq.size(); ++i) {
		rep += vec[seq[i]];
	}

	ans += k / (seq.size() - chain) * rep;
	k = k % (seq.size() - chain);
	for (long long i = chain; i < chain + k; ++i) {
		ans += vec[seq[i]];
	}

	cout << ans << endl;

	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}

