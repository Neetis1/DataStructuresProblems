/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3*/

class Solution {
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int numOfIslands = 0;

		if (grid.size() == 0)
			return 0;

		for (int row = 0; row < grid.size(); row++)
		{
			for (int col = 0; col < grid[row].size(); col++)
			{
				if (grid[row][col] == '1')
				{
					numOfIslands++;
					dfsSinkIsland(grid, row, col);
				}
			}
		}
		return numOfIslands;
	}

	void dfsSinkIsland(vector<vector<char>> &grid, int row, int col)
	{
		if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
			return;

		grid[row][col] = '0';

		dfsSinkIsland(grid, row + 1, col);
		dfsSinkIsland(grid, row - 1, col);
		dfsSinkIsland(grid, row, col + 1);
		dfsSinkIsland(grid, row, col - 1);

	}
};