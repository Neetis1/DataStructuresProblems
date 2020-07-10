/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int n1size = num1.size()-1;
        int n2size = num2.size()-1;
        int sum =0;
        
        while(n1size >=0 && n2size >=0){
            sum += num1[n1size] - '0' + num2[n2size] -'0';  // main take from this problem is this  -'0' karne se integer value milega :)   + '0' karne se string 
            result.push_back(sum%10 + '0');
            sum = sum/10;
            n1size--;
            n2size--;
        }
        while(n1size >=0){
            sum += num1[n1size] - '0';
            result.push_back(sum%10 + '0');
            sum = sum/10;
            n1size--;
        }
        while(n2size >=0){
            sum +=  num2[n2size] -'0';
            result.push_back(sum%10 + '0');
            sum = sum/10;
            n2size--;
        }
        if(sum >0){
            result.push_back(sum + '0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
