#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct SparseTable {
	int N = 1;
	int K = 0;
	vector<vector<int>> st;
	vector<int> lg;

	SparseTable(vector<int> &vec) {
		N = vec.size();
		K = ceil(log2(N));
		st.resize(N, vector<int>(K + 1));
		lg.resize(N + 1);

		lg[1] = 0;
		for (int i = 2; i <= N; ++i) lg[i] = lg[i / 2] + 1;

		for (int i = 0; i < vec.size(); ++i) st[i][0] = vec[i];
		for (int j = 1; j <= K; ++j)
			for (int i = 0; i + (1 << j) <= N; ++i)
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}

	// inclusive of both
	int rmq(int l, int r) {
		int j = lg[r - l + 1];
		return min(st[l][j], st[r - (1 << j) + 1][j]);
	}
};

int main() {
	return 0;
}
