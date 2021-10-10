class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        
        stack<pair<int,int>> s;
        int count = 0;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ++count;
                    s.push(make_pair(i,j));
                    while(!s.empty())
                    {
                        int x = s.top().first;
                        int y = s.top().second;
                        
                        s.pop();
                        
                        grid[x][y] = '0';
                        
                        if(y+1<m && grid[x][y+1]=='1')
                            s.push(make_pair(x,y+1));
                        if(x+1<n && grid[x+1][y] == '1')
                            s.push(make_pair(x+1,y));
                        if(x-1>=0 && grid[x-1][y]== '1')
                            s.push(make_pair(x-1,y));
                        if(y-1>=0 && grid[x][y-1]== '1')
                            s.push(make_pair(x,y-1));
                    }
                }
            }
        }
        return count;
        
    }
};