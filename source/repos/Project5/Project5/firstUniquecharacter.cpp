/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/

class Solution {
public:
	int firstUniqChar(string s)
	{
		vector<int> charArray(26);
		if (s.length() == 0)
			return -1;
		for (int index = 0; index < s.length(); index++)
		{
			charArray[s[index] - 'a']++;
			cout << charArray[s[index] - 'a'] << "\n";
		}

		for (int index = 0; index < s.length(); index++)
		{
			if (charArray[s[index] - 'a'] == 1)
				return index;
		}
		return -1;
	}
};