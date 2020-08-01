/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upper = false;
        int len = word.length();
        if(isupper(word[0]) && isupper(word[len-1]))
           upper = true;
        
        if(upper){
            for(int i=1;i<len; i++){
                if(islower(word[i]))
                    return false;
            }
        }else
        {
            for(int i=1;i<len; i++){
                if(isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};
