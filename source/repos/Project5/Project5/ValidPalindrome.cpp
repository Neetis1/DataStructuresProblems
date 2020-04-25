/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false*/

class Solution {
public:
	bool isPalindrome(string s) {
		vector<int>charArr(126);
		unordered_map<char, int> hash;
		string result;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			char c = tolower(s[i]);
			if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
				result += c;
		}
		int i = 0, j = result.length() - 1;
		while (i < j) {
			if (result[i] != result[j])
				return false;
			i++; j--;
		}
		return true;
	}
};