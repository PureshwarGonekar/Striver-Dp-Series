

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int longest=0;
        int i=0,j=0;
        while(s[j]!='\0'){
            if(mp.find(s[j]) != mp.end()){
                longest = max(longest, j-i);
                int newInd = mp[s[j]]+1;
                if(newInd > i) i= newInd;
            }
            mp[s[j]] = j;
            j++;
            
        }
        longest = max(longest, j-i);
        return longest;
    }
};