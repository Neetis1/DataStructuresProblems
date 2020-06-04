/*In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).*/

class Solution {
public:
    
    //["apap","app"]  
    //["hello","leetcode"]
//"abcdefghijklmnopqrstuvwxyz"
    bool isAlienSorted(vector<string>& words, string order) {
        int c[26];
        for(int i=0;i<order.size();i++){
            c[order[i] -'a'] = i;
        }
        for(int i =0;i<words.size()-1;i++){
            int n = min(words[i].size(),words[i+1].size());
            string word1 = words[i];
            string word2 = words[i+1];
            
            for(int j =0;j<n;j++){
                if(word1[j] != word2[j]){
                    if(c[word1[j]-'a'] > c[word2[j]-'a'])
                        return false;
                    n=-1;
                    break;
                }
            }
            if(n !=-1 && word1.size() > word2.size())
                return false;
        }
            return true;
    }
};
