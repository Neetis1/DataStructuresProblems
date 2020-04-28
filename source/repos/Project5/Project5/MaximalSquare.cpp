/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		int maxArea = 0;
		vector<vector<int>>DP(m + 1, vector<int>(n + 1));

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (matrix[i - 1][j - 1] == '0')
					continue;
				else {
					DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
				}
				maxArea = max(maxArea, DP[i][j]);
			}
		return maxArea * maxArea;
	}
};