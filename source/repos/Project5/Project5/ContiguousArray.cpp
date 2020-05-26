/*
Contiguous Array
Solution
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/


class Solution {
public:
	int findMaxLength(vector<int>& nums)
	{
		int sum = 0;
		unordered_map<int, int> m;
		unsigned int longestContArray = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				sum += -1;
			else
				sum += 1;

			auto it = m.find(sum);

			if (sum == 0)
			{
				if (longestContArray < i + 1)
					longestContArray = i + 1;
			}
			else if (it != m.end())
			{
				if (longestContArray < i - it->second)
					longestContArray = i - it->second;
			}
			else if (it == m.end())
				m.insert({ sum,i });
		}
		return longestContArray;
	}
};


// Solved again 

class Solution {
public:
    // This prblem we wll solve using a hashmap count and index, how? we will add +1 to the count if we encounter a 1 and
    //-1 if encounter a 0. we then store the index in the hasmap. we will also keep a max variable to store the max length 
    //occurrred so far and update it everytime we get any count value twice we update the max count if it greter than prev max  
    int findMaxLength(vector<int>& nums) {
        int s = nums.size();
        if(s ==0 || s==1)
            return 0;
        
        unordered_map<int,int>m;
        int maxCount=0;
        int count=0;
        m[count] = -1;
        for(int i=0;i<s;i++){
            if(nums[i] == 0) count--;
            else if(nums[i] ==1 ) count++;
            if(m.find(count) != m.end()){
                maxCount = max(maxCount, i - m[count]);
            }
            else
                m[count] =i;
        }
        return maxCount;
    }
};
