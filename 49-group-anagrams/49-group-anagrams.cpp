class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(auto const& str:strs)
        {
            string tmp{str};
            sort(tmp.begin(),tmp.end());
            groups[tmp].emplace_back(str);
        }
        
        
        vector<vector<string>> anagrams;
        for(auto const& kvp:groups)
        {
            vector<string> group;
            for(auto const& str:kvp.second)
            {
                group.emplace_back(str);
                
            }
            sort(group.begin(),group.end());
            anagrams.emplace_back(move(group));
        }
        return anagrams;
    }
};