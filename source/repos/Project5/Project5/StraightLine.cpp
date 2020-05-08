/*You are given an array coordinates, coordinates[i] = [x, y], where[x, y] represents the coordinate of a point.Check if these points make a straight line in the XY plane.





Example 1:



Input : coordinates = [[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]
Output : true
		 Example 2 :



	 Input : coordinates = [[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]
		 Output : false


			  Constraints :

						  2 <= coordinates.length <= 1000
						  coordinates[i].length == 2
						  - 10 ^ 4 <= coordinates[i][0], coordinates[i][1] <= 10 ^ 4
						  coordinates contains no duplicate point.
*/

class Solution {
public:
	/*
	we will calculate this by using the 1st hint so any points will always form a staight line so first we calcultate the slope between these 2 points by doing (x' - x'') / (y' - y'') now we can compare this initial slope with all other points given in the array by claculating there slope with 1st index if it is same we have got a straight line. The problem comes wen the diffrence between some Y points is 0 , then we get a divide by zero error. Now to handle that we could just use simple mathematices and cross multiple them,(x' - x'') / (y' - y'') = (x' - x1) / (y'-y1) == (x' - x'') * (y'-y1) = (x' - x1)*(y' - y'')

	*/
	bool checkStraightLine(vector<vector<int>>& coordinates) {

		if (coordinates.size() < 2)
			return false;
		if (coordinates.size() == 2)
			return true;
		int x = coordinates[0][0] - coordinates[1][0];
		int y = coordinates[0][1] - coordinates[1][1];

		for (int i = 2; i<coordinates.size(); i++){
			if (x* (coordinates[0][1] - coordinates[i][1]) != y *((coordinates[0][0] - coordinates[i][0])))
				return false;
		}
		return true;
	}
};
