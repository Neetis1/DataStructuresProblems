You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),
                    [](const string& a , const string& b){
                        // get the Identifier for a and b 
                        string IDa = a.substr(0,a.find(" ")); 
                        string IDb = b.substr(0,b.find(" "));
                        // get the 1st word after the identifier
                        string loga = a.substr(a.find(" ")+1);
                        string logb = b.substr(b.find(" ")+1);
                        // if both are letters then compare the words if words are equal we should compare the identifiers
                        if(!isdigit(logb[0]) && !isdigit(loga[0])){
                            if(loga != logb)
                                return loga < logb;
                            else
                                return IDa <IDb;
                        }
                        // if b is digit and a is not we should return so that swap is done as a should come first 
                        if(isdigit(logb[0]) && !isdigit(loga[0]))
                           return true;
                        // if a is digit and b is not then return false as no swapping is needed b should come 1st and it is at the right place
                        if(!isdigit(logb[0]) && isdigit(loga[0]))
                            return false;
                        
                        // if bothe are digit we need to maintain the order as it is.
                        return false; 
        });
        return logs;
    }
};
