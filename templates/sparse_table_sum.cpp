#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct SparseTable {
	int N = 1;
	int K = 0;
	vector<vector<int>> st;

	SparseTable(vector<int> &vec) {
		N = vec.size();
		K = ceil(log2(N));
		st.resize(N, vector<int>(K + 1));

		for (int i = 0; i < vec.size(); ++i) st[i][0] = vec[i];
		for (int j = 1; j <= K; ++j)
			for (int i = 0; i + (1 << j) <= N; ++i)
				st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
	}

	// inclusive of both
	int query(int l, int r) {
		int sum = 0;
		for (int j = K; j >= 0; --j) {
			if ((1 << j) <= r - l + 1) {
				sum += st[l][j];
				l += 1 << j;
			}
		}
		return sum;
	}
};

int main() {
	return 0;
}
