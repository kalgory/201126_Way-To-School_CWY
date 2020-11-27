#include <string>
#include <vector>

using namespace std;

int dp[101][101];
int count1 = 0;
int d(vector<vector<int>>& puddles, int m, int n) {
	// 집에 도착하면
	if (dp[m][n] == -1) {
		return 0;
	}
	if (m < 1 || n < 1) {
		return 0;
	}
	if (m == 1 && n == 1) {

		return 1;
	}
	// 이미 값이 있으면
	if (dp[m][n] > 0) {
		return dp[m][n] % 1000000007;
	}


	return dp[m][n] = (d(puddles, m - 1, n) + d(puddles, m, n - 1)) % 1000000007;

}

int solution(int m, int n, vector<vector<int>> puddles) {
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][0]][puddles[i][1]] = -1;
	}
	return d(puddles, m, n);
}