#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
	if (a[0] != b[0]) return a[0] < b[0];
	if (a[2] != b[2]) return a[2] < b[2];
	return a[1] < b[1];
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n + m, vector<int>(3));

	for (int i = 0; i < n; ++i) {
		cin >> vec[i][0];
	}
	for (int i = 0; i < n; ++i) {
		cin >> vec[i][1];
	}
	for (int i = 0; i < n; ++i) {
		vec[i][2] = 0;
	}
	for (int i = n; i < n + m; ++i) {
		cin >> vec[i][0];
	}
	for (int i = n; i < n + m; ++i) {
		cin >> vec[i][1];
	}
	for (int i = n; i < n + m; ++i) {
		vec[i][2] = 1;
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	multiset<int> ms;

	for (auto v : vec) {
		if (v[2] == 1) {
			ms.insert(v[1]);
		} else {
			auto it = ms.lower_bound(v[1]);
			if (it == ms.end()) {
				cout << "No" << endl;
				return;
			} else {
				ms.erase(it);
			}
		}
	}

	cout << "Yes" << endl;
	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
