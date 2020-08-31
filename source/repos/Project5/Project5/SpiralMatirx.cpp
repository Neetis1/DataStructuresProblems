Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return vector<int>();
        int n = matrix[0].size();
        
        vector<int>result;
        int lastRow = m-1;
        int lastCol = n-1;
        
        int rowIndex = 0;
        int colIndex = 0;
        
        while(rowIndex <= lastRow && colIndex <= lastCol){
            
            for(int i = colIndex; i <= lastCol; i++ )
                result.push_back(matrix[rowIndex][i]);
             rowIndex++;
            
            for(int i = rowIndex; i<= lastRow; i++)
                result.push_back(matrix[i][lastCol]);
            lastCol--;
            
            if(rowIndex <= lastRow){
                for(int i= lastCol; i>=colIndex; i-- )
                    result.push_back(matrix[lastRow][i]);
                lastRow--;
            }
            
            if(colIndex <= lastCol){
                for(int i= lastRow; i>=rowIndex; i-- )
                    result.push_back(matrix[i][colIndex]);
                colIndex++;
            }
        }
        return result;
    }
};
