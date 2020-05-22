/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

/*we will do this using a uordered_map to store the frequencies of the chars and then will put these values in to a max heap(priority queue which will keep the largest element in the top and then will use this max heap to create our string*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        priority_queue<pair<int,char>> heap;
        string result = "";
        
        for(auto i : s)
            freq[i]++;
        
        for(auto i : freq)
            heap.push({i.second,i.first});
        while(!heap.empty()){
            pair<int,char>s1 = heap.top();
            heap.pop();
            while(s1.first){
                s1.first--;
                result+=s1.second;
            }
        }
        return result;
    }
};
