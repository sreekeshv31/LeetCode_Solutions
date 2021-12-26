class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int low = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (low < hi) {
                    if (num[low] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[low]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (low < hi && num[low] == num[low+1]) low++;
                        while (low < hi && num[hi] == num[hi-1]) hi--;
                        
                        low++; hi--;
                    } 
                    else if (num[low] + num[hi] < sum) low++;
                    else hi--;
               }
            }
        }
        return res;
    }
};