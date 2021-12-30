class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int length = 0;
        int left = 0,right = 0,n = s.size();
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left = max(mpp[s[right]]+1,left);
            }
            mpp[s[right]] = right;
            length = max(length,right-left+1);
            right++;
        }
        return length;
        
    }
};