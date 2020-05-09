/*Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
public:
	/*
	if we have to find if the number is square or not ist thing we will think of is calculate the square of each number and one by one caompare, now can we optimize it, we just need to search for this squareroot from numbers 1 to NUM, now we know this is a sorted space, so what comes into our mind when things are sorted and we have to search for something. Binary Search!!! thats all now what we do is we devide our sorted space into half everytime, we check if the mid point value's square is equal to the num if yes then we return true, else if square is bigger than the value . we need to make high go lower else low value go higher by mid-1 or mid +1. thats alll :)
	*/
	bool isPerfectSquare(int num) {
		long lower, upper, guess;
		lower = 1;
		upper = num;
		while (upper >= lower){
			guess = (lower + upper) / 2;
			if (guess*guess == num)
				return true;
			if (guess*guess > num)
				upper = guess - 1;
			else
				lower = guess + 1;
		}
		return guess*guess == num;
	}
};