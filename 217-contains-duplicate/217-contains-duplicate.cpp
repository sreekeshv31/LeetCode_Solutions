class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        for(auto it:mp)
        {
            if(it.second >= 2)
                return true;
        }
        return false;
            
        
    }
};