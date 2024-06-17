class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return palin(s,left,right-1) || palin(s,left+1,right);
            }
            ++left,--right;
        }
        return true;
        
    }
    
    bool palin(const string s,int left,int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
        {
            return false;
        }
        ++left,--right;
            
        }
        return true;
        
    }
};