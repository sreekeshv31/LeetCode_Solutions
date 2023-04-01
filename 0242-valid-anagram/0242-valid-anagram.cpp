class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<char,int> count;
        for(const auto &c:s)
            ++count[c];
        
        for(const auto &c:t)
        {
            --count[c];
            if(count[c]<0)
                return false;
        }
        
        return true; // T-O(n) S -O(1)
            
        
    }
};