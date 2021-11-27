class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        sort(intervals.begin(),intervals.end()); //O(nlogn)
        
        vector<int> tempInterval = intervals[0];
        for(auto it : intervals)
        {
            if(it[0]<=tempInterval[1])
            {
                tempInterval[1] = max(tempInterval[1],it[1]);
            }
                
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
            
        }
    
   // T - O(nLogn) for sorting + O(N) for iterating
       // S - O(N)
        
    
};