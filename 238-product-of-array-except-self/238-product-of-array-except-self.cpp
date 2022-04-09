class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int Left = 1,Right = 1;
        vector<int> res(n,1);
        for(int i =0;i<n;i++)
        {
            res[i]*=Left;
            Left*=nums[i];
            res[n-1-i]*=Right;
            Right*=nums[n-1-i];
        }
        return res;
        
    }
};