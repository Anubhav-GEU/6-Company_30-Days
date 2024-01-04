class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        // vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1}; 
        while (q.empty() == false) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                int height = ans[row][col];
                q.pop();

                for (int i=0; i<4; i++) {
                    int nrow = delrow[i]+row;
                    int ncol = delcol[i]+col;

                    if (nrow >=0 && ncol >= 0 && nrow < m && ncol < n && isWater[nrow][ncol] != 1 && ans[nrow][ncol] == 0) {
                        ans[nrow][ncol] = height+1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return ans;
    }
};
