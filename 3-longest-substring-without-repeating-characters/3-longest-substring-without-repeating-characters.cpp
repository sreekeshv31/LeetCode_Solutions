class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0,l=0,n=s.size();
        for(int i = 0;i<n;i++)
        {
            while(st.count(s[i]))
            {
                ans = max(ans,i-l);
                st.erase(s[l]);
                l++;
            }
            st.emplace(s[i]);
        }
        return max(ans,(int)st.size());
        
    }
};