/*Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false*/

class Solution {
public:
    // So how did we get this answer, 1st thing n the most important thing to remember is what is log2 (log base 2) this means for example log2(32) we are asking here 2 raised to the power of what is 32. in this case it is 5. 2^5 = 32 we can get this using log2. now in this problem we will use the same logic. we will calculate floor and ceil of log2(n). if it is a power of 2 then an integer will be returned, otherwise a floating point number we can confirm this by calculating floor and ciel and compare them.
    bool isPowerOfTwo(int n) {
        return n && ceil(log2(n)) == floor(log2(n)); 
    }
};
