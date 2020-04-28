/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> sum;
		vector<int>result(2);
		if (nums.size() == 0)
			return result;
		for (int index = 0; index < nums.size(); index++) {
			if (sum.find(nums[index]) == sum.end()) {
				sum.insert(pair<int, int>(target - nums[index], index));
			}
			else {
				result[0] = sum[nums[index]];
				result[1] = index;
				break;
			}
		}
		return result;
	}
};