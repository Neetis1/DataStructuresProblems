/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		if (grid.size() == 0)
			return 0;
		vector<vector<int>>result(m, vector<int>(n));

		result[0][0] = grid[0][0];

		for (int i = 1; i < n; i++)
			result[0][i] = result[0][i - 1] + grid[0][i];

		for (int i = 1; i < m; i++)
			result[i][0] = result[i - 1][0] + grid[i][0];

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
			{
				result[i][j] = min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
			}
		return result[m - 1][n - 1];
	}
};