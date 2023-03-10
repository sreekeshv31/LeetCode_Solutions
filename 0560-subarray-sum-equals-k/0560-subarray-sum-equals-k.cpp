class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        int ans=0,currPrefix=0;
        prefixSum[0]++;
        for(int i=0;i<nums.size();i++)
        {
            currPrefix+=nums[i];
            ans+=prefixSum[currPrefix-k];
            prefixSum[currPrefix]++;
        }
        return ans;
    }
};