class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minlen = prices[0];
        for(int i = 1;i<prices.size();i++)
        {
            minlen = min(prices[i],minlen);
            profit = max(profit,(prices[i]-minlen));
                
        }
        return profit;
        
    }
};