class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> count;
        for(auto const& c:s)
            ++count[tolower(c)];
        
        for(auto const&c:t)
        {
            --count[tolower(c)];
            if(count[tolower(c)]<0)
                return false;
            
        }
        return true;
        
    }
};