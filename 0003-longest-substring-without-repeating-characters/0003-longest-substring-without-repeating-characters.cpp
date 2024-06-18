class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           unordered_set<char> ss;
        int i = 0, j=0, ans = 0;
        for (j = 0; j < s.size(); ++j) {
            while (ss.count(s[j])) ss.erase(s[i++]);
            ss.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
        
    
};