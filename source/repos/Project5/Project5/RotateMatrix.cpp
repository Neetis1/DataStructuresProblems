/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
] */

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix.size() != matrix[0].size())
			return;
		int n = matrix.size();
		int level = n - 1; //3
		int l = 0;

		while (l < level)
		{
			int first = l;
			int last = n - 1 - l;
			for (int i = first; i < last; i++)
			{
				int offset = i - first;
				int temp = matrix[first][i];
				matrix[first][i] = matrix[last - offset][first];
				matrix[last - offset][first] = matrix[last][last - offset];
				matrix[last][last - offset] = matrix[i][last];
				matrix[i][last] = temp;
			}
			l++;
		}
	}
};
//An easy and staightforward solution is to get the transpose of the matrix ie swap(matrix[i][j], matrix[j][i], then do reverse of each row its magical