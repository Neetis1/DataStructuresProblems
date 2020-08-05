/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

Solution Explanation: 
=====================================================================
As we need to Find The No is Power Of 4 or Not
We Can Solve It by doing Bit Manipulation
[if Any No is valid Power_Of_4 then It should Be valid Power_Of_2 as well]
Let's Suppose if They Are Asking For Finding is The No_is_Power_Of 2 or Not Then What shuld We
do :
We Just Trying To Find Is That No Have only One Set Bit Or Not
If there is only One Set Bit exist Then We Can blindly Say That It's A valid Power Of 2
So,The Same Idea We Need here But Do check One More Condition

What Is The 2nd Condition Would Be, Let's Find Out By analysing Few Example

1 2 4 8 16 32 64 128 256 592 1084 ...... -> This All Are Power Of Two [ Mean Having Only One Set Bit ]
1 4 16 64 256 1084......-> This All Are Power Of Four , Now We can Greedly Observe
That Between two power_of_4 there Was One Invaild Power_Of_4 Exist
So we need To chech that Condition Too

So Conditions Are :

    1. No of Set Bit Always Be Only ONE 
    2. That SetBit Possition Should Be always In odd Place [ starting from Left ] 
Let's See Example :

     No            Bit_re             SetBitPos       No_of_setBit          Valid_power_of_four
     64         1 0 0 0 0 0 0           7                  1                        True         <= :)
     128        1 0 0 0 0 0 0 0         8                  1                        False        <=2nd Condition fail :(
     18         1 0 0 1 0               5,2                2                        False        <=1st Condition Fail :( 
     32         1 0 0 0 0 0             6                  1                        False        <=2nd Condition fail :(
Time Complexcity O ( 1 )    =>as we Only Traverse Only Max 32 Bit 
Space Complexcity O ( 1)  => No Extra Space*/



class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1)
            return 0;
        int numOfOne=0;
        int bitPosition =0;
        int position=1;
        while(n){
            if(n & 1){
                numOfOne++;
                bitPosition=position;
            }
            position++;
            n = n>>1;
        }
        if(numOfOne == 1 && bitPosition%2!=0)
            return true;
        else
            return false;
    }
};
