/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language*/

class Solution {
public:
    /* Solution 1 : Brian Kernighan’s Algorithm:
    Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the
    rightmost set bit.
    for example :
    10 in binary is 00001010
    9 in binary is 00001001
    8 in binary is 00001000
    7 in binary is 00000111
    So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If     we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
    The beauty of this solution is the number of times it loops is equal to the number of set bits in a given          integer. */
    vector<int> countBits1(int num) {
        vector<int>countArr;
        int count=0;
        for(int i=0 ; i<=num;i++){
            int n =i;
            while(n){
                n = n & (n-1);
                count++;
            }
            countArr.push_back(count);
            count=0;
        }
        return countArr;
    }
    
    /*Solution 2 : Is based out of hint 3 which says "Or does the odd/even status of the number help you in calculating the number
    of 1s?" Here we can observe that if the number is even the number of set bits is N >>1 (right shift)(example : 
    10 in binary is 00001010 10>>1  will get 5(0101) and number of set bits in 5 is equal to number of set bits in 10 ; 
    But for odd number example 9 in binary is 00001001 if we right shift by 1 we get 4 (0100) which has 1 bit set if we add one 
    to this out put we will get answer for our number the same pattern can be followed for all the odd and even numbers, here again 
    we are using DP as we will be using the old answer to get the current number)
    */
    vector<int> countBits(int num) {
        vector<int> countArr(num+1);
        for(int i=0;i<=num;i++){
            if(i%2 ==0)
                countArr[i] = countArr[i>>1]; // even number
            else
                countArr[i] = countArr[i>>1]+1;
        }
        return countArr;
    }
    
};
