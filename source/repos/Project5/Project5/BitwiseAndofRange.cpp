/*Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0*/

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int count = 0; // to keep the count of the number of right shifts made to make m and n equal
		while (m != n) {
			m = m >> 1;		//right shift m and n by 1 and maintain a count until m and n are equal
			n = n >> 1;
			count++;
		}
		return m << count; // if you left shift the number by count you will get the output,magical 
		// to get this output you should try to solve one or two examples and try and look for the pattern.
	}
};