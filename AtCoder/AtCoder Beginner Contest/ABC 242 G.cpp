#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <map>

using namespace std;

// data structure
vector<int> vec;
vector<int> freq(1e5+5);
long long current_ans = 0;

void remove(int idx) {
	int val = vec[idx];
	long long cur_freq = freq[val];
	current_ans -= cur_freq / 2;
	--freq[val];
	--cur_freq;
	current_ans += cur_freq / 2;
}
void add(int idx) {
	int val = vec[idx];
	long long cur_freq = freq[val];
	current_ans -= cur_freq / 2;
	++freq[val];
	++cur_freq;
	current_ans += cur_freq / 2;
}

long long get_answer() {
	return current_ans;
}

const int block_size = 316;

struct Query {
	int l, r, idx;
	bool operator<(Query other) const
	{
		return make_pair(l / block_size, r) <
		make_pair(other.l / block_size, other.r);
	}
};

bool cmp(Query &p, Query &q) {
    if (p.l / block_size != q.l / block_size)
        return p < q;
    return (p.l / block_size & 1) ? (p.r < q.r) : (p.r > q.r);
}


vector<long long> mo_s_algorithm(vector<Query> queries) {
	vector<long long> answers(queries.size());
	sort(queries.begin(), queries.end(), cmp);

	// TODO: initialize data structure

	int cur_l = 0;
	int cur_r = -1;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (Query q : queries) {
		while (cur_l > q.l) {
			cur_l--;
			add(cur_l);
		}
		while (cur_r < q.r) {
			cur_r++;
			add(cur_r);
		}
		while (cur_l < q.l) {
			remove(cur_l);
			cur_l++;
		}
		while (cur_r > q.r) {
			remove(cur_r);
			cur_r--;
		}
		answers[q.idx] = get_answer();
	}
	return answers;
}

void solve() {
	int n;
	cin >> n;
	vec.resize(n);
	for (int &x : vec) cin >> x;

	int q;
	cin >> q;
	vector<Query> queries;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		queries.push_back({l, r, i});
	}

	auto answers = mo_s_algorithm(queries);
	for (auto a : answers) cout << a << endl;
	return;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	return 0;
}
