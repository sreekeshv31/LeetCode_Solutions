class Solution {
public:
    int bfs(map<int, int>&mp, int n, int start)
    {
        queue<int>q;
        q.push(start);
        set<int>visited; 
        visited.insert(start);
        int steps = 0;
        //==================================================
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n * n) return steps;

                for (int next = curr + 1; next <= (curr + 6); next++)
                {
                    int actualNext = (mp.count(next))? mp[next] : next; //jump to the next value
                    if (visited.find(actualNext) != visited.end()) continue;

                    visited.insert(actualNext);
                    q.push(actualNext);
                }
            }
            steps++;
        }
        //=====================================================
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        map<int, int>mp;
        for (int i = n - 1; i >= 0; i--) //moving from bottom to top
        {
            int actualRowIdx = (n - i - 1);   //rowIndex from bottom 
            int low = (actualRowIdx * n) + 1, high = low + n - 1;  //range of values in currRow
            int forwardCellIdx = low, reverseCellIdx = high;
            //for EvenRow Idx => (low->high)
            //fir OddRow Idx => (high->low)
            //===============================================
            for (int j = 0; j < n; j++)
            {
                int actualCellIdx = (actualRowIdx % 2 == 0)? forwardCellIdx : reverseCellIdx;
                if (board[i][j] != -1) mp[actualCellIdx] = board[i][j];
                forwardCellIdx++;
                reverseCellIdx--;
            }
            //================================================
        }
        set<int>visited;
        int ans = bfs(mp, n, 1);
        return (ans == INT_MAX? -1 : ans);
        
    }
};