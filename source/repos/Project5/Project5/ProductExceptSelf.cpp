/*Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int length = nums.size();
		vector<int>leftProduct(length);
		vector<int>rightProduct(length);
		leftProduct[0] = 1;
		rightProduct[length - 1] = 1;

		for (int leftIndex = 0, rightIndex = length - 1; leftIndex < length - 1, rightIndex>0; leftIndex++, rightIndex--)
		{
			leftProduct[leftIndex + 1] = nums[leftIndex] * leftProduct[leftIndex];
			rightProduct[rightIndex - 1] = nums[rightIndex] * rightProduct[rightIndex];
		}

		for (int index = 0; index < length; index++)
		{
			leftProduct[index] = leftProduct[index] * rightProduct[index];
		}
		return leftProduct;
	}
};