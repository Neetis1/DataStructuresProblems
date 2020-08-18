/*Numbers With Same Consecutive Differences

Solution
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if(N == 1){
            for(int i=0;i<=9;i++)
                result.push_back(i);
            return result;
        }
        for( int i=1 ; i<=9;i++)
            getNumber(N,K,i,i,1,result);
        return result;
    }
    
    void getNumber(int N, int K, int currNum, int prevNum, int numIndex ,vector<int>&result){
        if(numIndex == N){
            result.push_back(currNum);
            return;
        }
        int num = prevNum + K;
        if(num <10){
            getNumber(N,K,(currNum * 10) + num, num, numIndex+1, result);
        }
        num = prevNum - K;
        if(K >0 && num >=0){
            getNumber(N,K,(currNum * 10) + num, num, numIndex+1, result);
        }
    }
};
