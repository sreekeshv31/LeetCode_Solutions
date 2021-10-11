class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        
        sort(boxTypes.begin(),boxTypes.end(),[](const auto&a,const auto&b)
             {
                 return a[1]>b[1];
             });
        
        int result = 0;
        
        for(auto &boxtype : boxTypes)
        {
            if(truckSize>boxtype[0])
            {
                truckSize-=boxtype[0];
                result+=boxtype[0]*boxtype[1];
            }
            else
            {
                result+=truckSize*boxtype[1];
                break;
            }
        }
        return result;
        
    }
};