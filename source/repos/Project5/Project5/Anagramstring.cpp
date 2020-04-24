/*Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int>charA(26);
		int slen = s.length();
		int tlen = t.length();
		if (slen != tlen)
			return false;
		if (slen == 0 && tlen == 0)
			return true;
		for (int i = 0; i < slen; i++) {
			charA[s[i] - 'a']++;
		}
		for (int i = 0; i < slen; i++) {
			if (charA[t[i] - 'a'] == 0)
				return false;
			else
				charA[t[i] - 'a']--;
		}
		return true;
	}
};